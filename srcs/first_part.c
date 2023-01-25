/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:00:43 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 19:04:54 by tchevrie         ###   ########.fr       */
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