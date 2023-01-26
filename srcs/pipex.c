/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/26 11:28:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex(char **args, int size, t_env *env)
{
	int		fd[2];
	int		pipefd[2];
	int		middle_cmds;
	size_t	i;
	int		return_value;

	fd[1] = -1;
	fd[0] = open_infile(args[0]);
	if (!first_part(fd, pipefd, args[1], env))
		return (1);
	middle_cmds = size - 4;
	i = 1;
	while (middle_cmds-- > 0)
	{
		middle_part(fd, pipefd, args[1 + i], env);
		i++;
	}
	if (fd[0] > 0)
		close(fd[0]);
	fd[0] = -1;
	fd[1] = open_outfile(args[size - 1]);
	if (fd[1] == -1)
		return (end_pipex(fd, env->path), 1);
	return_value = last_part(fd, pipefd, args[size - 2], env);
	return (end_pipex(fd, env->path), return_value);
}

static int	here_doc(char **args, int size, t_env *env)
{
	int		fd[2];
	int		pipefd[2];
	int		middle_cmds;
	size_t	i;
	int		return_value;

	fd[0] = 0;
	if (!here_doc_first_part(fd, pipefd, args[1], env))
		return (1);
	middle_cmds = size - 4;
	i = 1;
	while (middle_cmds > 0)
	{
		middle_part(fd, pipefd, args[1 + i], env);
		middle_cmds--;
		i++;
	}
	fd[1] = here_doc_open_outfile(args[size - 1]);
	if (fd[1] == -1)
		return (end_pipex(fd, env->path), 1);
	return_value = last_part(fd, pipefd, args[size - 2], env);
	return (end_pipex(fd, env->path), return_value);
}

int	main(int argc, char **argv, char *envp[])
{
	t_env	env;

	if (argc < 5 || (argc > 1 && argc < 6 \
	&& ft_strcmp(argv[1], "here_doc") == 0))
		return (ft_putstr_fd(ERR_NOTENOUGHARGS, 2), 1);
	env.envp = envp;
	env.path = get_path(envp);
	if (!(env.path))
		return (ft_putstr_fd(ERR_PATHNOTFOUND, 2), 1);
	else if (ft_strcmp(argv[1], "here_doc") == 0)
		return (here_doc(argv + 1, argc - 1, &env));
	else
		return (pipex(argv + 1, argc - 1, &env));
}
