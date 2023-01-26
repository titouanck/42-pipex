/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:01:25 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/26 12:43:05 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	last_part(int fd[2], int pipefd[2], char *arg, t_env *env)
{
	int	pid;
	int	status;

	close(pipefd[1]);
	pid = fork();
	if (pid == -1)
		return (perror("pipex: fork"), \
		close(pipefd[0]), close(pipefd[1]), end_pipex(fd, env->path), 0);
	else if (pid == 0)
	{
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		status = execute_cmd(arg, env);
		close(pipefd[0]);
		end_pipex(fd, env->path);
		exit(status);
	}
	else
	{
		wait(&status);
		close(pipefd[0]);
	}
	return (status);
}
