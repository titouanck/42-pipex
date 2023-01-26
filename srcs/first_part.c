/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:00:43 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/26 15:36:24 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	first_part_child(int fd[2], int pipefd[2], char *arg, t_env *env)
{
	close(pipefd[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	execute_cmd(arg, env);
	end_pipex(fd, env->path);
	close(pipefd[1]);
	exit(1);
}

int	first_part(int fd[2], int pipefd[2], char *arg, t_env *env)
{
	int	pid;

	if (pipe(pipefd) == -1)
		return (perror("pipex: pipe"), end_pipex(fd, env->path), 0);
	if (fd[0] == -1)
		return (1);
	pid = fork();
	if (pid == -1)
	{
		perror("pipex: fork");
		return (close(pipefd[0]), close(pipefd[1]), \
		end_pipex(fd, env->path), 0);
	}
	else if (pid == 0)
		first_part_child(fd, pipefd, arg, env);
	return (1);
}

int	here_doc_first_part(int fd[2], int pipefd[2], char *arg, t_env *env)
{
	char	*line;

	if (pipe(pipefd) == -1)
		return (perror("pipex: pipe"), end_pipex(fd, env->path), 0);
	arg = ft_strjoin(arg, "\n");
	ft_putstr("> ");
	while (1)
	{
		line = get_next_line(fd[0]);
		if (line && ft_strcmp(line, arg) == 0)
		{
			free(line);
			break ;
		}
		else if (line && ft_strchr(line, '\n'))
			ft_putstr("> ");
		if (line && ft_strcmp(line, arg) != 0)
		{
			ft_putstr_fd(line, pipefd[1]);
			free(line);
		}	
	}
	return (1);
}
