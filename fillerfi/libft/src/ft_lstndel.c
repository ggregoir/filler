/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstndel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 17:05:02 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstndel(t_list **alst, size_t n)
{
	t_list	*list;
	t_list	*tmp;

	if (!alst || !(*alst) || !n)
		return (0);
	list = *alst;
	tmp = NULL;
	if (n > 1)
	{
		if ((ft_lstgo(&list, n - 1) == n - 1) && list->next)
			tmp = list->next;
		if (tmp && tmp->next)
			list->next = tmp->next;
		else
			list->next = NULL;
		list = tmp;
	}
	else if (list->next)
		*alst = list->next;
	else if (!(list->next))
		*alst = NULL;
	if (list)
		free(list->content);
	free(list);
	return (!(*alst) ? 0 : 1);
}
