/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 01:57:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/26 00:16:41 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_infile(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

static int	open_outfile(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (fd);
}

static int	here_doc_open_outfile(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (fd);
}

int	open_files(char *infile, char *outfile, int fd[2])
{
	if (!infile)
	{
		*(fd + 1) = here_doc_open_outfile(outfile);
		if (*(fd + 1) == -1)
			return (ft_putstr_fd("pipex: ", 2), perror(outfile), 0);
		return (1);
	}
	else
	{
		*(fd + 0) = open_infile(infile);
		if (*(fd + 0) == -1)
			return (ft_putstr_fd("pipex: ", 2), perror(infile), 0);
		*(fd + 1) = open_outfile(outfile);
		if (*(fd + 1) == -1)
		{
			close(*(fd + 0));
			*(fd + 0) = -1;
			return (ft_putstr_fd("pipex: ", 2), perror(outfile), 0);
		}
		return (1);
	}
}
