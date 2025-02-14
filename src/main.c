/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:21:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/14 15:21:36 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av)
{
	int		fd[2];
	pit_t	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		pid = fork;
		if (pid == -1)
			ft_error();
		else if (pid == 0)
			child(av, env, fd);
	}
}
