/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:27:09 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/26 01:25:53 by tchevrie         ###   ########.fr       */
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

typedef struct s_env
{
	char	**path;
	char	**envp;
}			t_env;

// first_part.c
int		first_part(int fd[2], int pipefd[2], char *arg, t_env *env);
int		here_doc_first_part(int fd[2], int pipefd[2], char *arg, t_env *env);

// middle_part.c
int		middle_part(int fd[2], int pipefd[2], char *arg, t_env *env);

// last_part.c
int		last_part(int fd[2], int pipefd[2], char *arg, t_env *env);

// get_path.c
char	**get_path(char *envp[]);

// open_files.c
int		open_infile(const char *filename);
int		open_outfile(const char *filename);
int		here_doc_open_outfile(const char *filename);

// execute_cmd.c
int		execute_cmd(char *cmd, t_env *env);

// end_pipex.c
void	end_pipex(int fd[2], char **path);

// utils.c
void	print_file(int fd);
void	print_path(char **path);

#endif