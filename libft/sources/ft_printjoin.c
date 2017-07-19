/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:51:35 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/05/24 15:01:41 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printjoin(char *delim, char **arr, size_t size)
{
	if (!arr || !*arr)
		return ;
	while (size--)
	{
		ft_putstr(*arr++);
		if (size >= 1)
			ft_putstr(delim);
	}
}
