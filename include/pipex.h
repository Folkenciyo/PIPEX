/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:18:40 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/24 19:51:09uguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include "libft.h"
#include "ft_printf.h"

/**
 * @brief Structure to store the data of the program
 *  
 * @param fd[2] extreme of the pipe
 * @param fd_in fd of the input file
 * @param fd_out fd of the output file
 * @param cmd commands to execute
 * @param envp environment
 * @param path path
 * @param file_in path of the input file
 * @param file_out path of the output file
 */
typedef struct s_pipex
{
	int		p_fd[2];
	int		fd_in;
	int		fd_out;
	char	***cmd;
	char	**cmd_paths;
	char	***chosen_path;
	char	*path;
	char	*cmds_path[3];
	char	*infile;
	char	*outfile;
}	t_pipex;

/***** EXECUTABLE PIPEX *****/

void	ft_exec(t_pipex *pipex, char *const *envp);

/***** ERROR FUNCTIONS *****/

void	error_one(char *str_perror, int exit_);

void	error_two(char *str_perror, char *file, int exit_);

/***** MEMORY FUNCTIONS *****/

t_pipex	*init_pipex(t_pipex *pipex, char **argv);

void	init_chosen_path(t_pipex *pipex);

void	ft_cleanup(t_pipex *pipex);

/***** UTILS FUNCTIONS *****/

char	*ft_strjoin_p(char *s1, char const *s2);
