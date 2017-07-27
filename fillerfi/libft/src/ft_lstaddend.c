/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:10:28 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!alst || !new)
		return (0);
	list = *alst;
	if (!list)
	{
		*alst = new;
		return (1);
	}
	while (list->next)
		list = list->next;
	list->next = new;
	return (1);
}
