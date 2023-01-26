/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:41:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/26 11:23:45 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	try_to_execute(t_env *env, char **args)
{
	size_t	i;
	char	*bin;

	i = 0;
	while (1)
	{
		if (!((env->path)[i]))
			break ;
		bin = ft_strrjoin((env->path)[i], "/", args[0]);
		if (!bin)
			return (ft_putstr_fd(ERR_ALLOC, 2), free_tabstr(args), 0);
		if (execve(bin, args, env->envp) <= 0)
		{
			free(bin);
			bin = NULL;
		}
		i++;
	}
	return (1);
}

int	execute_cmd(char *cmd, t_env *env)
{
	char	**args;
	int		status;
	char	*err;

	args = ft_split(cmd, ' ');
	if (!args)
		return (ft_putstr_fd(ERR_ALLOC, 2), 0);
	status = try_to_execute(env, args);
	if (status == 0)
		return (0);
	err = ft_strrjoin("pipex: command not found: ", args[0], "\n");
	ft_putstr_fd(err, 2);
	if (err)
		free(err);
	return (free_tabstr(args), status);
}
