/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:17:25 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/25 02:57:09 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_one(char *str_perror, int exit_)
{
	perror(str_perror);
	ft_printf("Error Description: %s\n",
		strerror(errno));
	exit(exit_);
}

void	error_two(char *str_perror, char *file, int exit_)
{
	perror(str_perror);
	ft_printf("Error Description: %s\nNo such file or directory: %s\n",
		strerror(errno), file);
	exit(exit_);
}
