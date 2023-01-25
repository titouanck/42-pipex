/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:01:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 17:36:23 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_file(int fd)
{
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_putstr_fd(line, 2);
		free(line);
	}
}

void	print_path(char **path)
{
	size_t	i;

	if (!path)
		return ;
	i = 0;
	while (path[i])
	{
		ft_printf("%s\n", path[i]);
		i++;
	}
}
