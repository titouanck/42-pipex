/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:41:59 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 02:42:05 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd(char *cmd, char **path)
{
	size_t	i;
	char	*bin;
	char	**args;
	char	*env[1];

	env[0] = NULL;
	args = ft_split(cmd, ' ');
	if (!args)
		return (0);
	i = 0;
	while (1)
	{
		if (!(path[i]))
			break ;
		bin = ft_strrjoin(path[i], "/", args[0]);
		if (!bin)
			return (0);
		if (execve(bin, args, env) > 0)
			return (free(args), free(bin), 1);
		free(bin);
		i++;
	}
	return (perror(cmd), free(args), 0);
}