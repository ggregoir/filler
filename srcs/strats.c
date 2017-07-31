/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:13:57 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/31 19:24:17 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int			can_place(t_struct *s, int x, int y, int *nb)
{
	if (y < 0 || x < 0 || y >= s->mapy || x >= s->mapx
	|| (s->map[y][x] != '.' && s->map[y][x] != s->me && s->map[y][x] != ft_tolower(s->me)))
		return (0);
	else if (s->map[y][x] == s->me || s->map[y][x] == ft_tolower(s->me))
		(*nb)++;
	return (*nb < 2);
}

int			place_piece(t_struct *s, int yi, int xi)
{
	int		i;
	int		j;
	int 	x;
	int 	y;
	int		nb;

	j = -1;
	nb = 0;
	while (++j < s->piecey)
	{
		i = -1;
		while (++i < s->piecex)
		{
			if (s->piece[j][i] == '*')
			{
				y = j + yi;
				x = i + xi;
				if (y >= s->mapy || x >= s->mapx || !can_place(s, x, y, &nb))
				{
					return (0);
				}
			}
		}
	}
	return (nb == 1);
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


void			get_strat(t_struct *s)
{
	int		curr;
	int		best;
	int 	x;
	int 	y;

	best = 1024;
	y = -1 - s->stary;
	while (++y < s->mapy)
	{
		x = -1 - s->starx;
		while (++x < s->mapx)
		{
			if (place_piece(s, x, y))
			{
				if ((curr = get_best_cell(s, x, y)) < best)
				{
					best = curr;
					s->x = x;
					s->y = y;
				}
			}
		}
	}
}
