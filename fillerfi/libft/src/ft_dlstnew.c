/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 00:31:10 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist *newdlist;

	if (!(newdlist = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	if (!content)
	{
		newdlist->content = NULL;
		newdlist->content_size = 0;
	}
	else
	{
		if (!(newdlist->content = malloc(content_size)))
		{
			free(newdlist);
			return (NULL);
		}
		ft_memcpy(newdlist->content, content, content_size);
		newdlist->content_size = content_size;
	}
	newdlist->next = NULL;
	newdlist->back = NULL;
	return (newdlist);
}
