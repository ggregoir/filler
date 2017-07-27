/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:13:15 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:14 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		last;

	i = 0;
	j = 0;
	last = 0;
	if (!s2[0])
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s2[j] == s1[i])
		{
			if (s2[j + 1] == '\0')
				return ((char*)(s1 + i - j));
			j++;
		}
		else
		{
			i = last++;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
