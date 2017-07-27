/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:42:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstgo(t_list **alst, size_t n)
{
	size_t	i;

	i = 1;
	if (!alst || !(*alst))
		return (0);
	if (!n)
	{
		while ((*alst)->next)
		{
			*alst = (*alst)->next;
			i++;
		}
		return (i);
	}
	while ((*alst)->next && n-- > 1)
	{
		*alst = (*alst)->next;
		i++;
	}
	return (i);
}
