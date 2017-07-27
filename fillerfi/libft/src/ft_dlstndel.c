/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstndel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 02:29:03 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlstndel(t_dlist **dlst, size_t n, int dir)
{
	t_dlist	*dlist;

	if (!dlst || !(*dlst) || !n)
		return (-1);
	dlist = *dlst;
	if (n == 1 && !(dlist->next) && !(dlist->back))
		*dlst = NULL;
	else if (n == 1 && dlist->back)
		*dlst = dlist->back;
	else if (n == 1 && dlist->next)
		*dlst = dlist->next;
	else if (ft_dlstgo(&dlist, n, dir) != n)
		return (-1);
	if (dlist->next)
		dlist->next->back = dlist->back ? dlist->back : NULL;
	if (dlist->back)
		dlist->back->next = dlist->next ? dlist->next : NULL;
	if (dlist->content)
		free(dlist->content);
	free(dlist);
	return (!(*dlst) ? 0 : 1);
}
