/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:56:37 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 02:56:43 by tchevrie         ###   ########.fr       */
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
		ft_printf(line);
		free(line);
	}
}