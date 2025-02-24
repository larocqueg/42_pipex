/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:38:14 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/14 17:40:21 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **av, char **env, int *fd)
{
	int	fd_infile;

	fd_infile = open(av[1], O_RDONLY, 0777);
	if (fd_infile == -1)
		ft_error(INFILE_ERROR);
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd_infile, STDIN_FILENO);
		execute(av[2], env);
	}
}

void	parent(char **av, char **env, int *fd)
{
	int	fd_outfile;

	fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
		ft_error (OUTFILE_ERROR);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		execute(av[3], env);
	}
}

char	*path_finder(char *cmds, char **env)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!env[i])
		ft_error(PATH_ERROR);
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmds);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	ft_free(paths);
	return (0);
}

void	execute(char *av, char **env)
{
	int		x;
	char	*path;
	char	**cmds;

	cmds = ft_split(av, ' ');
	if (!cmds)
		return ;
	path = path_finder(cmds[0], env);
	if (!path)
	{
		ft_free(cmds);
		ft_error(NULL);
	}
	x = execve(path, cmds, env);
	if (x == -1)
		ft_error(NULL);
}
