/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:56:03 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/27 16:16:41 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	img_put_pixel(t_env *e, t_img *img, t_pos idx, int c)
{
	int		pos;
	int		size;

	size = ((e->map.y * 10 - 1) * e->img.sl) + (e->map.x * 10 * e->img.bpp / 8);
	pos = (idx.y * img->sl) + (idx.x * img->bpp / 8);
	if (pos > 0 && pos + 2 < size && idx.x >= 0
		&& (idx.x * e->img.bpp / 8) < e->img.sl)
	{
		if (img->edn)
		{
			img->d[pos] = mlx_get_color_value(e->mlx, c / 0x10000 % 0x100);
			img->d[pos + 1] = mlx_get_color_value(e->mlx, c / 0x100 % 0x100);
			img->d[pos + 2] = mlx_get_color_value(e->mlx, c % 0x100);
		}
		else
		{
			img->d[pos] = mlx_get_color_value(e->mlx, c % 0x100);
			img->d[pos + 1] = mlx_get_color_value(e->mlx, c / 0x100 % 0x100);
			img->d[pos + 2] = mlx_get_color_value(e->mlx, c / 0x10000 % 0x100);
		}
	}
}

static void	clear_img(t_img *img, t_env *e)
{
	t_pos	idx;
	int		pos;

	idx.y = -1;
	while (++idx.y < e->map.y * 10)
	{
		idx.x = -1;
		while (++idx.x < e->map.x * 10)
		{
			pos = (idx.y * img->sl) + (idx.x * img->bpp / 8);
			img->d[pos] = 0;
			img->d[pos + 1] = 0;
			img->d[pos + 2] = 0;
		}
	}
}

static void	add_cell(t_env *e, t_pos pos, char map[e->map.y][e->map.x])
{
	t_pos	idx;
	t_pos	end;

	idx = set_position(-1 + pos.x * 10, -1 + pos.y * 10);
	end = set_position(idx.x + 10, idx.y + 10);
	while (++idx.y < end.y)
	{
		idx.x = end.x - 10;
		while (++idx.x < end.x)
		{
			if (map[pos.y][pos.x] == '.')
				img_put_pixel(e, &(e->img), idx, 0x918787);
			else if (map[pos.y][pos.x] == 'X' || map[pos.y][pos.x] == 'x')
				img_put_pixel(e, &(e->img), idx, 0x212D9A);
			else if (map[pos.y][pos.x] == 'O' || map[pos.y][pos.x] == 'o')
				img_put_pixel(e, &(e->img), idx, 0xAB2020);
		}
	}
}

void		make_graph(t_env *e, char map[e->map.y][e->map.x])
{
	t_pos	idx;

	clear_img(&(e->img), e);
	idx.y = -1;
	while (++idx.y < e->map.y)
	{
		idx.x = -1;
		while (++idx.x < e->map.x)
			add_cell(e, idx, map);
	}
}

int			display_graph(void *env)
{
	t_env	*e;

	e = (t_env*)env;
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	return (SUCCESS);
}
