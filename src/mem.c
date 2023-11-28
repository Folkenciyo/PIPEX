/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:38:24 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/28 20:47:39 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

t_pipex	*init_pipex(t_pipex *pipex)
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
		pipex->chosen_path[j] = (char **)ft_calloc(sizeof(char *),  i + 1);
		if (pipex->chosen_path[j] == NULL)
			return ;
		j++;
	}
	pipex->chosen_path[j] = NULL;
}
