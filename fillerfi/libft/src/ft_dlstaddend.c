/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:44:16 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddend(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*dlist;

	if (!dlst || !new)
		return ;
	dlist = *dlst;
	if (!dlist)
	{
		*dlst = new;
		return ;
	}
	while (dlist->next)
		dlist = dlist->next;
	new->back = dlist;
	dlist->next = new;
}
