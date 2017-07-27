/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstgo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:53:30 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstgo(t_dlist **dlst, size_t n, int dir)
{
	size_t	i;

	i = 1;
	if (!dlst || !(*dlst))
		return (0);
	if (!n)
	{
		while ((dir ? (*dlst)->next : (*dlst)->back))
		{
			*dlst = dir ? (*dlst)->next : (*dlst)->back;
			i++;
		}
		return (i);
	}
	while ((dir ? (*dlst)->next : (*dlst)->back) && n-- > 1)
	{
		*dlst = dir ? (*dlst)->next : (*dlst)->back;
		i++;
	}
	return (i);
}
