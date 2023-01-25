/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 01:16:15 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex(char **path)
{
	print_path(path);
}

int	main(int argc, char **argv, char *envp[])
{
	char	**path;
	
	if (argc < 1)
		return (ft_printf(ERR_NOTENOUGHARGS), 1);
	path = get_path(envp);
	if (!path)
		return (ft_printf(ERR_PATHNOTFOUND), 1);
	else
		return (pipex(path), 0);
}