/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:58:31 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/05/24 14:58:32 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	index;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		index = 0;
		while (big[index] == little[index])
			if (!little[++index])
				return ((char *)big);
		big++;
	}
	return (0);
}
