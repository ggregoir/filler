/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:14:14 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:23:42 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t destlen;
	size_t i;

	i = 0;
	destlen = ft_strlen(s1);
	while (s2[i])
	{
		s1[destlen + i] = s2[i];
		i++;
	}
	s1[destlen + i] = '\0';
	return (s1);
}
