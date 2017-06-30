/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:50:06 by ggregoir          #+#    #+#             */
/*   Updated: 2017/06/21 23:24:46 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	m;
	char	*str;
	char	*ret;
	size_t	i;

	m = start;
	i = 0;
	if (!s)
		return (NULL);
	if ((str = (char *)malloc(sizeof(*str) * len + 1)) == NULL)
		return (NULL);
	while (start != len + m)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	ret = str;
	free(str);
	return (ret);
}
