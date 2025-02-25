/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:09:19 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/17 13:13:13 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *str)
{
	if (str != NULL)
		ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_command_error(char **cmds)
{
	ft_putstr_fd("Error: command not found \"", 2);
	if (cmds[0])
		ft_putstr_fd(cmds[0], 2);
	ft_putstr_fd("\"\n", 2);
	ft_free(cmds);
}
