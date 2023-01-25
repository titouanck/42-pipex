/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:41:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 17:31:45 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd(char *cmd, char **path)
{
	size_t	i;
	char	*bin;
	char	**args;
	char	*env[1];
	int		pid;

	env[0] = NULL;
	args = ft_split(cmd, ' ');
	if (!args)
		return (ft_putstr_fd(ERR_ALLOC, 2), 0);
	pid = fork();
	if (pid == -1)
		return (perror("fork()"), free_split(args), 0);
	if (pid == 0)
	{
		i = 0;
		while (1)
		{
			if (!(path[i]))
				break ;
			bin = ft_strrjoin(path[i], "/", args[0]);
			if (!bin)
				return (ft_putstr_fd(ERR_ALLOC, 2), free_split(args), 0);
			if (execve(bin, args, env) <= 0)
			{
				free(bin);
				bin = NULL;
			}
			i++;
		}
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd("\n", 2);
	}
	else
		wait(NULL);
	return (free_split(args), 0);
}
