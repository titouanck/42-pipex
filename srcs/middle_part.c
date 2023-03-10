/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:01:05 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/26 12:41:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	middle_part_pid_0(int new_pipefd[2], int pipefd[2], \
	char *arg, t_env *env)
{
	close(new_pipefd[0]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(new_pipefd[1], STDOUT_FILENO);
	execute_cmd(arg, env);
	close(pipefd[0]);
	close(new_pipefd[1]);
}

int	middle_part(int fd[2], int pipefd[2], char *arg, t_env *env)
{
	int	pid;
	int	new_pipefd[2];

	close(pipefd[1]);
	if (pipe(new_pipefd) == -1)
		return (perror("pipex: pipe"), end_pipex(fd, env->path), 0);
	pid = fork();
	if (pid == -1)
		return (perror("pipex: fork"), \
		close(pipefd[0]), close(pipefd[1]), end_pipex(fd, env->path), 0);
	else if (pid == 0)
	{
		middle_part_pid_0(new_pipefd, pipefd, arg, env);
		end_pipex(fd, env->path);
		exit(1);
	}
	else
	{
		pipefd[0] = new_pipefd[0];
		pipefd[1] = new_pipefd[1];
	}
	return (1);
}
