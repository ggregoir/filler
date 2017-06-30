/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:49:48 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:23:13 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dend;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dend = i;
	while (src[i - dend] && i + 1 < size)
	{
		dst[i] = src[i - dend];
		i++;
	}
	if (dend < size)
		dst[i] = '\0';
	return (dend + ft_strlen(src));
}
