/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:27:09 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 04:33:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>

# define ERR_NOTENOUGHARGS "pipex: not enough arguments.\n"
# define ERR_PATHNOTFOUND "pipex: could not find PATH.\n"

// get_path.c
void		print_path(char **path);
char		**get_path(char *envp[]);
void		free_path(char **path);

// open_files.c
int			open_files(char *infile, char *outfile, int fd[2]);
int			open_infile(const char *filename);
int			open_outfile(const char *filename);

// execute_cmd.c
int			execute_cmd(char *cmd, char **path);

#endif