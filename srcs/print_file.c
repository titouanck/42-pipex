/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:01:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 16:44:04 by tchevrie         ###   ########.fr       */
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