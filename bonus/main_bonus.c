/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:01:35 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 22:01:59 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	(void)env;
	(void)av;
	if (ac >= 5)
	{
	}
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(AV_ERROR_BONUS, 2);
	return (1);
}
