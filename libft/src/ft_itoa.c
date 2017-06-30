/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:20:17 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:24:00 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		nb_n(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = nb_n(n) - 1;
	if ((str = (char*)malloc(sizeof(*str) * (nb_n(n) + 1))) == NULL)
		return (NULL);
	str[nb_n(n)] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i] = '0' + n;
	return (str);
}
