/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 22:29:09 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/31 18:46:03 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_abs(int nb)
{
	return (nb = (nb < 0 ? -nb : nb));
}

int			get_distance(int x, int y, int i, int j)
{
	int		dist;

	dist = ft_abs(x - i) + ft_abs(y - j);
	return (dist);
}
