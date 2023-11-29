/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:17:25 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/29 20:07:53 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_one(char *str_perror, int exit_)
{
	perror(str_perror);
	exit(exit_);
}

void	error_two(char *str_perror, char *file, int exit_)
{
	ft_printf("%s: %s\nNo such file or directory: %s\n",
		str_perror, strerror(errno), file);
	exit(exit_);
}
