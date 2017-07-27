/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:10:34 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/27 15:21:08 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		delete_win(void *env)
{
	t_env *e;

	e = (t_env*)env;
	ft_putstr("0 0\n");
	mlx_destroy_image(e->mlx, e->img.i);
	mlx_destroy_window(e->mlx, e->win);
	exit(EXIT_FAILURE);
	return (SUCCESS);
}

int		get_distance(t_pos a, t_pos b)
{
	int		dist;

	dist = ft_abs(a.x - b.x) + ft_abs(a.y - b.y);
	return (dist);
}

t_pos	set_position(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

int		cell_type(t_env *e, char cell)
{
	char	enemy;

	enemy = (e->player == 'X' ? 'O' : 'X');
	if (cell == '.')
		return (0);
	if (cell == e->player || cell == e->player + LOWCASE)
		return (1);
	if (cell == enemy || cell == enemy + LOWCASE)
		return (2);
	else
		return (3);
}

void	put_position(t_env *e, t_pos final)
{
	if (final.y == -100 && final.x == -100)
	{
		ft_putstr("0 0\n");
		mlx_destroy_image(e->mlx, e->img.i);
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_FAILURE);
	}
	ft_putnbr(final.y);
	ft_putchar(' ');
	ft_putnbr(final.x);
	ft_putchar('\n');
}
