/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:49:43 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/05/24 15:01:33 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t x;

	x = -1;
	while (++x < n)
		if (((t_byte *)s1)[x] != ((t_byte *)s2)[x])
			return (((t_byte *)s1)[x] - ((t_byte *)s2)[x]);
	return (0);
}
