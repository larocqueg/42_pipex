/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:21:23 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/02/14 15:21:24 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// access, dup, dup2, execve, fork, pipe
# include <unistd.h>
// open
# include <fcntl.h>
// wait, waitpid
# include <sys/wait.h>
// pid_t
# include <sys/types.h>
// malloc, free, exit
# include <stdlib.h>
// perror
# include <stdio.h>
// stderror
# include <string.h>
// libf with ft_printf & get_next_line
# include "../libft/libft.h"

typedef	struct	s_pipe
{
}	t_pipex;

#endif
