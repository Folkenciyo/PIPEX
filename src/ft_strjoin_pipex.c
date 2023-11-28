/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:16:10 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/28 18:30:26 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_p(char *s1, char const *s2)
{
	char	*new_str;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	i = 0;
	if (!new_str || !s1 || !s2)
		return (NULL);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	while (i < s1_len + s2_len + 1 - 1)
	{
		new_str[i] = *s2++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}