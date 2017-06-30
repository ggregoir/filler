/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:15:34 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:19:36 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_lencus(char const *s)
{
	int		i;
	int		j;
	int		f;

	i = 0;
	j = 0;
	f = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
		f--;
	j = f - i;
	if (j <= 0)
		j = 0;
	return (j);
}

static int	ft_fullblank(char const *swagg)
{
	int		i;

	i = 0;
	while (swagg[i])
	{
		if (swagg[i] != ' ' || swagg[i] != '\n' || swagg[i] != '\t')
		{
			return (2);
		}
		i++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s || (str = (char *)malloc(sizeof(*str) * ft_lencus(s) + 2)) == NULL)
		return (NULL);
	if (ft_fullblank(s) == 2)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (j < ft_lencus(s) + 1)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	if (ft_fullblank(s) == 1)
	{
		str[0] = '\0';
		return (str);
	}
	return (str);
}
