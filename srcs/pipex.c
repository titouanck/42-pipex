/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 19:05:05 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex(char **args, int size, char **path)
{
	int		fd[2];
	int		pipefd[2];
	int		middle_cmds;
	size_t	i;
	int		return_value;

	if (!open_files(args[0], args[size - 1], fd))
		return (free_tabstr(path), 0);
	if (!first_part(fd, pipefd, args[1], path))
		return (0);
	middle_cmds = size - 4;
	i = 1;
	while (middle_cmds > 0)
	{
		middle_part(fd, pipefd, args[1 + i], path);
		middle_cmds--;
		i++;
	}
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
		return (!pipex(argv + 1, argc - 1, path));
}
