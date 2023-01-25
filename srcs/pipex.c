/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 18:02:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_part(int fd[2], int pipefd[2], char *arg, char **path)
{
	int	pid;
	
	if (pipe(pipefd) == -1)
		return (perror("pipex: pipe"), end_pipex(fd, path), 0);
	pid = fork();
	if (pid == -1)
	{
		perror("pipex: fork");		
		return (close(pipefd[0]), close(pipefd[1]), end_pipex(fd, path), 0);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		execute_cmd(arg, path);
		end_pipex(fd, path);
		close(pipefd[1]);
		exit(1);
	}
	else
		wait(NULL);
	return (1);
}

// int	middle_part(int fd[2], int pipefd[2], char *arg, char **path)
// {
// 	int	pid;
// 	int	new_pipefd[2];

// 	ft_putstr_fd("On rentre dans middle_part()\n", 2);
// 	if (pipe(new_pipefd) == -1)
// 		return (perror("pipe()"), end_pipex(fd, path), 0);
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork()");		
// 		return (close(pipefd[0]), close(pipefd[1]), end_pipex(fd, path), 0);
// 	}
// 	else if (pid == 0)
// 	{
// 		close(pipefd[1]);
// 		close(new_pipefd[0]);
// 		dup2(pipefd[0], STDIN_FILENO);
// 		dup2(new_pipefd[1], STDOUT_FILENO);
// 		execute_cmd(arg, path);
// 		close(pipefd[0]);
// 		close(new_pipefd[1]);
// 	}
// 	else
// 	{
// 		close(pipefd[0]);
// 		close(pipefd[1]);
// 		pipefd[0] = new_pipefd[0];
// 		pipefd[1] = new_pipefd[1];
// 	}
// 	return (1);
// }

int	last_part(int fd[2], int pipefd[2], char *arg, char **path)
{
	int	pid;

	close(pipefd[1]);
	pid = fork();
	if (pid == -1)
	{
		perror("pipex: fork");		
		return (close(pipefd[0]), close(pipefd[1]), end_pipex(fd, path), 0);
	}
	else if (pid == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execute_cmd(arg, path);
		close(pipefd[0]);
		end_pipex(fd, path);
		exit(1);
	}
	else
	{
		wait(NULL);
		close(pipefd[0]);
	}
	return (1);
}

static int	pipex(char **args, int size, char **path)
{
	int		fd[2];
	int		pipefd[2];
	int		return_value;
	// int		middle_cmds;
	// size_t	i;

	if (!open_files(args[0], args[size - 1], fd))
		return (free_tabstr(path), 0);
	if (!first_part(fd, pipefd, args[1], path))
		return (0);
	// middle_cmds = size - 4;
	// i = 1;
	// while (middle_cmds > 0)
	// {
	// 	middle_part(fd, pipefd, args[1 + i], path);
	// 	middle_cmds--;
	// 	i++;
	// }
	return_value = last_part(fd, pipefd, args[size - 2], path);
	return (end_pipex(fd, path), return_value);
}

int	main(int argc, char **argv, char *envp[])
{
	char	**path;
	
	if (argc < 5)
		return (ft_printf(ERR_NOTENOUGHARGS), 1);
	path = get_path(envp);
	if (!path)
		return (ft_printf(ERR_PATHNOTFOUND), 1);
	else
		return (pipex(argv + 1, argc - 1, path));
}