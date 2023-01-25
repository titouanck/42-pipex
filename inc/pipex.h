/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:27:09 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 17:40:25 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define ERR_NOTENOUGHARGS "pipex: not enough arguments.\n"
# define ERR_PATHNOTFOUND "pipex: could not find PATH.\n"
# define ERR_ALLOC "pipex: could not allocate memory.\n"

typedef struct s_fd
{
	int	in;
	int	out;
}		t_fd;

// get_path.c
char		**get_path(char *envp[]);

// open_files.c
int			open_files(char *infile, char *outfile, int fd[2]);

// execute_cmd.c
int			execute_cmd(char *cmd, char **path);

// end_pipex.c
void		end_pipex(int fd[2], char **path);

// utils.c
void		print_file(int fd);
void		print_path(char **path);


#endif