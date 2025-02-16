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
		ft_error();
	else
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd_infile, STDOUT_FILENO);
		execute(av[2], env);
	}
}

void	parent(char **av, char **env, int *fd)
{
	int	fd_outfile;

	fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_outfile == -1)
		ft_error ();
	else
	{
		close(fd[1]);
		dup2(fd[0], STDOUT_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		execute(av[3], env);
	}
}

void	execute(char *av, char **env)
{
	(void)av;
	(void)env;
	return ;
}

void	ft_error(void)
{
	ft_putstr_fd("Error", 2);
	exit(EXIT_FAILURE);
}

