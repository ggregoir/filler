/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 16:29:27 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/08 18:13:44 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/filler.h"

void			ft_getplayers(t_struct *s)
{
	char 		*line;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_atoi(line + 10) == 1)
		{
			s->enemy = 'X';
			s->me = 'O';
		}
		else if (ft_atoi(line + 10) == 2)
		{
			s->enemy = 'O';
			s->me = 'X';
		}
		//free(line);
	}
}

void			ft_getpiece(t_struct *s)
{
	char 		*line;
	int			i;

	get_next_line(0, &line);
	if (!s->piecex && !s->piecey)
	{
		s->piecex = ft_atoi(line + 6);
		s->piecey = ft_atoi(line + 8);
	}
	s->piece = ft_memalloc(sizeof(char*) * (s->piecey + 1));
	i = 0;
	while(i < s->piecey)
	{
		if (get_next_line(0, &line) > 0)
		{
			s->piece[i] = ft_strdup(line);
			free(line);
		}
		i++;
	}
}

void			ft_getinitpos(t_struct *s)
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
	if (s->enemyy > s->mey)
		s->dir = 1;
}

void			ft_getmap(t_struct *s)
{
	char 		*line;
	int			i;

	s->map = ft_memalloc(sizeof(char*) * (s->mapy + 1));
	get_next_line(0, &line);

	i = 0;
	while(i < s->mapy)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (!(s->map[i] = ft_strdup(line + 4)))
				error(2);
			//free(line);
		}
		i++;
	}
	ft_getpiece(s);
	if (s->enemyx == 0 && s->enemyy == 0 && s->mex == 0 && s->mey == 0)
		ft_getinitpos(s);

}

int 			main()
{
	t_struct	s;
	char 		*line;

	ft_init_struct(&s);
	ft_getplayers(&s);
	while (get_next_line(0, &line) > 0)
	{
		if (!s.mapx && !s.mapy)
		{
			s.mapx = ft_atoi(line + 8);
			s.mapy = ft_atoi(line + 11);
		}
		//free(line);
		ft_getmap(&s);
		if (!ft_get_enemy_play(&s))
			s.stop = 1;
		ft_print_piece(&s);
		if (ft_end(&s) == 1)
			break ;
	}
	return (0);
}
