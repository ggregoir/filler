/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:57:58 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:20:38 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_c(char *str, char c)
{
	int		nbm;
	int		i;

	nbm = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			nbm++;
		i++;
	}
	return (nbm);
}

static char	*ft_strdup_cus(char *src, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while ((src[i] != c) && src[i])
		i++;
	str = (char*)malloc(sizeof(*src) * (i + 1));
	j = 0;
	while (j < i)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		m;
	int		i;
	int		check;

	i = -1;
	m = 0;
	check = 0;
	if (!str)
		return (NULL);
	if ((tab = malloc(sizeof(char*) * ft_c((char *)str, c) + 1)) == NULL)
		return (NULL);
	while (str[++i])
	{
		if ((str[i] != c) && str[i] && !check)
		{
			tab[m] = ft_strdup_cus((char *)(str + i), c);
			m++;
			check = 1;
		}
		if (str[i] == c)
			check = 0;
	}
	tab[m] = NULL;
	return (tab);
}
