/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:21:48 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:14 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(dst);
	if (len > size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && (int)(size - len - 1) > 0)
	{
		dst[len + i] = src[i];
		i++;
		size--;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
