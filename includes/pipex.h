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

// Macros
# define INFILE_ERROR "Error: No such file or directory \"infile\"\n"
# define OUTFILE_ERROR "Error: No such file or directory \"outfile\"\n"
# define AV_ERROR_1		"Error: Bad arguments!\n"
# define AV_ERROR_2	"Usage: $> ./pipex \"file1\" \"cmd1\" \"cmd2\" \"file2\"\n"
# define PID_ERROR	"Error while trying to create a fork!\n"
# define PIPE_ERROR	"Error while trying to create a pipe!\n"
# define PATH_ERROR	"Error: PATH not found!\n"

// utils.c
void	child(char **av, char **env, int *fd);
void	parent(char **av, char **env, int *fd);
char	*path_finder(char *cmds, char **env);
void	execute(char *av, char **env);

// error.c
void	ft_error(char *str);
void	ft_free(char **str);
void	ft_command_error(char **cmds);

#endif
