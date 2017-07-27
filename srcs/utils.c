/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:04:20 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/27 23:47:20 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

// int fd = 0;

int				ft_end(t_struct *s)
{
	int i;

	i = -1;
	while(i++ < s->piecey)
	{
		free(s->map[i]);
		s->map[i] = NULL;
	}
	free(s->piece);
	free(s->map);
	if (s->stop == 1)
	{
		//free(s);
		return (0);
	}
	return (1);
}

void			ft_print_piece(t_struct *s)
{
	int fd = 0;
	if (fd == 0)
		fd = open("/dev/ttys001", O_WRONLY);
	ft_putendl_fd(ft_itoa(s->y), fd);
	ft_putnbr(s->x);
	ft_putchar(' ');
	ft_putnbr(s->y);
	ft_putendl_fd(ft_itoa(s->x), fd);
	ft_putchar('\n');
}

void			ft_init_struct(t_struct *s)
{
	s->stop = 0;
	s->mex = 0 ;
	s->mey = 0;
	s->piecex = 0;
	s->piecey = 0;
	s->me = 0;
	s->enemy = 0;
	s->starx = 512;
	s->stary = 512;
}
/*
void			get_near_enemy(t_struct *s)
{
	int x;
	int y;

	y = 0;
	while(y != s->mapy)
	{
		x = 0;
		while(x != s->mapx)
		{
			if (s->map[y][x] == s->me)
			{
				s->mex = x;
				s->mey = y;
			}
			if (s->map[y][x] == s->enemy)
			{
				s->enemyx = x;
				s->enemyy = y;
			}
			x++;
		}
		y++;
	}
}
*/
int				ft_get_enemy_play(t_struct *s)
{
	get_strat(s);
	return (0);
}
