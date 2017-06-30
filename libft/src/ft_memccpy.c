/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:35:21 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:23:52 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		(*(unsigned char *)dst++) = (*(unsigned char *)src);
		if ((*(unsigned char *)src++) == ((unsigned char)c))
			return ((unsigned char*)dst);
		i++;
	}
	return (NULL);
}
