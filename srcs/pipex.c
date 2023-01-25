/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 03:34:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex(char **args, int size, char **path)
{
	int	fd[2];
	int	pid;

	open_files(args[0], args[3], fd);
	pid = fork();
	if (pid == -1)
	{
		perror("fork()");
		return (close(fd[0]), close(fd[1]), free(path), 0);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		close(fd[1]);
		execute_cmd(args[1], path);
		return (1);
	}
	else
		wait(NULL);
		print_file(fd[0]);
	return (close(fd[0]), close(fd[1]), free(path), 1);
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