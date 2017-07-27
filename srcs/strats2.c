/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 22:29:09 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/27 23:17:52 by ggregoir         ###   ########.fr       */
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

int			get_piece_dist(t_struct *s, int xii, int yii, int xi, int yi)
{
	int		i;
	int		j;
	int 	x;
	int 	y;
	int		dist;

	dist = 0;
	y = -1;
	while (++y < s->piecey)
	{
		x = -1;
		while (++x < s->piecex)
		{
			if (s->piece[y][x] == '*')
			{
				i = xi + x;
				j = yi + y;
				dist += get_distance(xii, yii, i, j);
			}
		}
	}
	return (dist);
}

int			get_best_cell(t_struct *s, int yi, int xi)
{
	int 	x;
	int 	y;
	int		best;
	int		tmp;

	y = -1;
	best = 1024;
	while (++y < s->mapy)
	{
		x = -1;
		while (++x < s->mapx)
		{
			if (cell_type(s, s->map[y][x]) == 2)
			{
				if ((tmp = get_piece_dist(s, x, y, xi, yi)) < best)
					best = tmp;
			}
		}
	}
	return (best);
}

int			can_place(t_struct *s, int x, int y, int *nb)
{
	if (y < 0 || x < 0 || y >= s->mapy || x >= s->mapx
	|| (s->map[y][x] != '.' && s->map[y][x] != s->me && s->map[y][x] != ft_tolower(s->me)))
		return (0);
	else if (s->map[y][x] == s->me || s->map[y][x] == ft_tolower(s->me))
		(*nb)++;
	return (*nb < 2);
}
