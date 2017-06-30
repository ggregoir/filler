/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:02:32 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:23:53 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if ((mem = (void *)malloc(sizeof(*mem) * size)) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
