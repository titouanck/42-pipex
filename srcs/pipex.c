/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:58 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/25 21:14:22 by tchevrie         ###   ########.fr       */
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

	if (!open_files(args[0], args[size - 1], fd))
		return (free_tabstr(env->path), 0);
	if (!first_part(fd, pipefd, args[1], env))
		return (0);
	middle_cmds = size - 4;
	i = 1;
	while (middle_cmds > 0)
	{
		middle_part(fd, pipefd, args[1 + i], env);
		middle_cmds--;
		i++;
	}
	return_value = last_part(fd, pipefd, args[size - 2], env);
	return (end_pipex(fd, env->path), return_value);
}

int	main(int argc, char **argv, char *envp[])
{
	t_env	env;

	if (argc < 5)
		return (ft_putstr_fd(ERR_NOTENOUGHARGS, 2), 1);
	env.envp = envp;
	env.path = get_path(envp);
	if (!(env.path))
		return (ft_putstr_fd(ERR_PATHNOTFOUND, 2), 1);
	else
		return (pipex(argv + 1, argc - 1, &env));
}
