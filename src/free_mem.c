/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:24:44 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/29 19:18:12 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_str3(char ***str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j][i])
		{
			free(str[j][i]);
			str[j][i] = NULL;
			i++;
		}
		free(str[j]);
		str[j] = NULL;
		i = 0;
		j++;
	}
	free(str);
}

void	ft_free_str2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_cleanup(t_pipex *pipex)
{
	ft_free_str3(pipex->cmd);
	ft_free_str2(pipex->cmd_paths);
	ft_free_str3(pipex->chosen_path);
	free(pipex->cmds_path[0]);
	free(pipex->cmds_path[1]);
	free(pipex);
}
