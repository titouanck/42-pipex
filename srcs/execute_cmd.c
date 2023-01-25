/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:41:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 19:10:10 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	execute_cmd_pid_0(char *cmd, char **path, char **args)
{
	char	*env[1];
	size_t	i;
	char	*bin;

	env[0] = NULL;
	i = 0;
	while (1)
	{
		if (!(path[i]))
			break ;
		bin = ft_strrjoin(path[i], "/", args[0]);
		if (!bin)
			return (ft_putstr_fd(ERR_ALLOC, 2), free_tabstr(args), 0);
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
	return (1);
}

int	execute_cmd(char *cmd, char **path)
{
	char	**args;
	int		pid;
	int		return_value;

	args = ft_split(cmd, ' ');
	if (!args)
		return (ft_putstr_fd(ERR_ALLOC, 2), 0);
	pid = fork();
	if (pid == -1)
		return (perror("pipex: fork"), free_tabstr(args), 0);
	if (pid == 0)
	{
		return_value = execute_cmd_pid_0(cmd, path, args);
		if (return_value == 0)
			return (0);
	}
	else
		wait(NULL);
	return (free_tabstr(args), 0);
}
