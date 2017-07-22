/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 16:29:27 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/22 03:08:05 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/filler.h"



void			ft_getplayers(t_struct *s)
{
	/*int x;
	x = 0;
	while (s->tmp[x])
	{
		printf("%s\n", s->tmp[x]);
		x++;
	}
	*/
	//printf("%s\n",s->tmp[0] + 10);
	if (ft_atoi(s->tmp[0] + 10) == 1)
	{
		s->enemy = 'X';
		s->me = 'O';
	}
	else
	{
		s->enemy = 'O';
		s->me = 'X';
	}
	if (!s->mapx && !s->mapy)
		{
			s->mapy = ft_atoi(s->tmp[1] + 8);
			s->mapx = ft_atoi(s->tmp[1] + 11);
		}
}

void			ft_getpiece(t_struct *s)
{
	int			i;
	int 		j;

	j = s->mapy + 3;
	if (!s->piecex && !s->piecey)
	{
		s->piecey = ft_atoi(s->tmp[j] + 6);
		s->piecex = ft_atoi(s->tmp[j] + 8);
	}
	j++;
	s->piece = ft_memalloc(sizeof(char*) * (s->piecey + 1));
	i = 0;
	while(i < s->piecey)
	{
		if (s->tmp[j] != 0)
			s->piece[i] = ft_strdup(s->tmp[j]);
		i++;
		j++;
	}
}

void			ft_getinitpos(t_struct *s)
{
	int x;
	int y;
	int i;

	i = 0;
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
	if (s->enemyy > s->mey)
		s->dir = 1;
}

void			ft_getmap(t_struct *s)
{
	int			i;

	s->map = ft_memalloc(sizeof(char*) * (s->mapy + 1));
	i = 0;
	while(i < s->mapy)
	{
		if (!(s->map[i] = ft_strdup(s->tmp[i + 3] + 4)))
			error(2);
		i++;
	}
	ft_getpiece(s);
	if (s->enemyx == 0 && s->enemyy == 0 && s->mex == 0 && s->mey == 0)
		ft_getinitpos(s);
}

int 			main()
{
	t_struct	s;
	int			free;

	/*if (fd == 0)
		fd = open("/dev/ttys002", O_WRONLY);
	ft_putstr_fd("test", fd);*/

	ft_init_struct(&s);
	while (1)
	{
		if ((free = get_all(&s)) > 0)
		{
			ft_getplayers(&s);
			ft_getmap(&s);
			//printf("player = %c mapx = %d mapy = %d piecex = %d piecey = %d mex = %d mey = %d enemyx = %d enemyy = %d  \n", s.me,s.mapx, s.mapy, s.piecex, s.piecey, s.mex, s.mey, s.enemyx, s.enemyy);
			if (!ft_get_enemy_play(&s))
				s.stop = 1;
			ft_print_piece(&s);
			//printf("mapx = %d mapy = %d piecex = %d piecey = %d mex = %d mey = %d enemyx = %d enemyy = %d  \n", s.mapx, s.mapy, s.piecex, s.piecey, s.mex, s.mey, s.enemyx, s.enemyy);
			if (ft_end(&s))
				break;
		}
	}
	return (0);
}
