/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 04:52:24 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex(char **args, int size, char **path)
{
	int	fd[2];

	if (!open_files(args[0], args[3], fd))
		return (free(path), 1);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execute_cmd(args[1], path);
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