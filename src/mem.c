/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:38:24 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/29 19:12:43 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

t_pipex	*init_pipex(t_pipex *pipex, char **argv)
{
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
	{
		free(pipex);
		pipex = NULL;
		perror("Error opening file");
		ft_printf("Error Description: %s\n",
			strerror(errno));
		exit(EXIT_SUCCESS);
	}
	pipex->infile = argv[1];
	pipex->outfile = argv[4];
	pipex->fd_in = open(pipex->infile, O_RDONLY);
	pipex->fd_out = open(pipex->outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (pipex->fd_in == -1 || pipex->fd_out == -1)
		error_two("Error opening file", pipex->infile, EXIT_FAILURE);
	pipex->p_fd[0] = pipex->fd_in;
	pipex->p_fd[1] = pipex->fd_out;
	return (pipex);
}

void	init_chosen_path(t_pipex *pipex)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	pipex->chosen_path = (char ***)malloc(sizeof(char **) * 3);
	if (!pipex->chosen_path)
		return ;
	while (pipex->cmd_paths[i])
		i++;
	while (j < 2)
	{
		pipex->chosen_path[j] = (char **)malloc(sizeof(char *) * (i + 1));
		if (pipex->chosen_path[j] == NULL)
			return ;
		j++;
	}
	pipex->chosen_path[j] = NULL;
}
