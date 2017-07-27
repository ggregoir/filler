/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:18:57 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/27 15:21:39 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	can_place(t_env *e, char c, int *nb, t_pos curr)
{
	if (curr.y < 0 || curr.x < 0 || curr.y >= e->map.y || curr.x >= e->map.x
	|| (c != '.' && c != e->player && c != e->player + LOWCASE))
		return (ERROR);
	else if (c == e->player || c == e->player + LOWCASE)
		(*nb)++;
	return (*nb < 2);
}

static int	place_piece(t_env *e, char map[e->map.y][e->map.x], \
						char piece[e->piece.y][e->piece.x], t_pos map_idx)
{
	t_pos	idx;
	t_pos	curr;
	int		nb;

	idx.y = -1;
	nb = 0;
	while (++idx.y < e->piece.y)
	{
		idx.x = -1;
		while (++idx.x < e->piece.x)
		{
			if (piece[idx.y][idx.x] == '*')
			{
				curr = set_position(idx.x + map_idx.x, idx.y + map_idx.y);
				if (curr.y >= e->map.y || curr.x >= e->map.x
				|| !can_place(e, map[curr.y][curr.x], &nb, curr))
					return (ERROR);
			}
		}
	}
	return (nb == 1);
}

static int	get_piece_dist(t_env *e, char piece[e->piece.y][e->piece.x], \
							t_pos i, t_pos map_idx)
{
	t_pos	idx;
	t_pos	curr;
	int		dist;

	dist = 0;
	idx.y = -1;
	while (++idx.y < e->piece.y)
	{
		idx.x = -1;
		while (++idx.x < e->piece.x)
		{
			if (piece[idx.y][idx.x] == '*')
			{
				curr = set_position(map_idx.x + idx.x, map_idx.y + idx.y);
				dist += get_distance(i, curr);
			}
		}
	}
	return (dist);
}

static int	get_best_cell(t_env *e, char map[e->map.y][e->map.x], \
						char piece[e->piece.y][e->piece.x], t_pos map_idx)
{
	t_pos	idx;
	int		curr;
	int		best;

	idx.y = -1;
	best = BIG_SIZE;
	while (++idx.y < e->map.y)
	{
		idx.x = -1;
		while (++idx.x < e->map.x)
		{
			if (cell_type(e, map[idx.y][idx.x]) == 2)
			{
				if ((curr = get_piece_dist(e, piece, idx, map_idx)) < best)
					best = curr;
			}
		}
	}
	return (best);
}

void		get_placement(t_env *e, char map[e->map.y][e->map.x], \
						char piece[e->piece.y][e->piece.x])
{
	t_pos	idx;
	int		curr;
	int		best;

	best = BIG_SIZE;
	idx.y = -1 - e->star.y;
	e->best = set_position(NS_SIZE, NS_SIZE);
	while (++idx.y < e->map.y)
	{
		idx.x = -1 - e->star.x;
		while (++idx.x < e->map.x)
		{
			if (place_piece(e, map, piece, idx))
			{
				if ((curr = get_best_cell(e, map, piece, idx)) < best)
				{
					best = curr;
					e->best = idx;
				}
			}
		}
	}
	make_graph(e, map);
	display_graph((void*)e);
	put_position(e, e->best);
}
