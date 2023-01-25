/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 12:32:50 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_part(int fd[2], int pipefd[2], char *arg, char **path)
{
	close(pipefd[0]);
	dup2(fd[0], STDIN_FILENO);		
	dup2(pipefd[1], STDOUT_FILENO);
	execute_cmd(arg, path);
	close(pipefd[1]);
}

int	last_part(int fd[2], int pipefd[2], char *arg, char **path)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork()");		
		return (close(pipefd[0]), close(pipefd[1]), end_pipex(fd, path), 0);
	}
	else if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execute_cmd(arg, path);
		close(pipefd[0]);
	}
	else
	{
		wait(NULL);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	return (1);
}

static int	pipex(char **args, int size, char **path)
{
	int	fd[2];
	int	pipefd[2];
	int pid;
	int	return_value;

	if (!open_files(args[0], args[3], fd))
		return (free_path(path), 0);
	else if (pipe(pipefd) == -1)
		return (perror("pipe()"), end_pipex(fd, path), 0);
	pid = fork();
	if (pid == -1)
	{
		perror("fork()");		
		return (close(pipefd[0]), close(pipefd[1]), end_pipex(fd, path), 0);
	}
	else if (pid == 0)
		first_part(fd, pipefd, args[1], path);
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