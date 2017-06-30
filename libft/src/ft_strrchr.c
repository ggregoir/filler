/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:43:07 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:20:37 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (s[1] == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			j = i;
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		j = i;
	}
	if (j == 0)
		return ((char *)s);
	if (j == -1)
		return (NULL);
	return ((char *)s + (j));
}
