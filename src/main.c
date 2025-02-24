/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:21:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/14 17:41:49 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			ft_error(PIPE_ERROR);
		pid = fork();
		if (pid == -1)
			ft_error(PID_ERROR);
		else if (pid == 0)
			child(av, env, fd);
		wait(NULL);
		parent(av, env, fd);
		return (0);
	}
	ft_putstr_fd(AV_ERROR_1, 2);
	ft_putstr_fd(AV_ERROR_2, 2);
	return (1);
}
