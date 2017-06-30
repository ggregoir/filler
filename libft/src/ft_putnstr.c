/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:02:34 by ggregoir          #+#    #+#             */
/*   Updated: 2017/06/21 23:30:57 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putnstr(const char *str, int n)
{
	int i;

	i = 0;
	while (i != n)
	{
		ft_putchar(str[i]);
		i++;
	}
}
