hdsdsddgdfjkjsnfgkjsfs/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 16:29:27 by ggregoir          #+#    #+#             */
/*   Updated: 2017/06/30 16:36:22 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void			ft_getplayers(t_struct *s)
{
		if (get_next_line(0, &line) > 0)
	{
		if (ft_atoi(line + 10) == 1)
		{
			s->enemy = 'X'
			s->me = 'O'
		}
		else if (ft_atoi(line + 10) == 2)
		{
			s->enemy = 'O'
			s->me = 'X'
		}
		free(line);
	}
}

void			ft_getpiece(t_struct *s)
{
	char 		*line;
	int			i;

	get_next_line(0, &line);
	if (!s.piecex && !s.piecey)
	{
		s.piecex = ft_atoi(line + 6)
		s.piecey = ft_atoi(line + 8)
	}
	s->piece = ft_memalloc(sizeof(char*) * (s->piecey + 1));
	i = 0;
	while(i < s->piecey)
	{
		get_next_line(0, &line)
		s->piecey[i] = ft_strdup(line);
		free(line);
		i++;
	}
}

void			ft_getinitpos(t_struct *s)
{
	int x;
	int y;

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
		j++;
	}
	if (s->enemyy > s->mey)
		s->dir = DOWNRIGHT;
}

void			ft_getmap(t_struct *s)
{
	char 		*line
	int			i;

	f->map = ft_memalloc(sizeof(char*) * (f->mapy + 1));
	if (get_next_line(0,&line) > 0)
		free(line);
	i = 0;
	while(i < f->mapy)
	{
		get_next_line(0, &line)
		f->mapy[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	ft_getpiece(s);
	if (f->enemyx == 0 && f->enemyy == 0 && f->mex == 0 && f->mey == 0)
		ft_getinitpos(s);

}

int 			main()
{
	t_struct	s;
	char 		*line;

	ft_getplayers(&s)
	while (get_next_line(0, &line) > 0)
	{
		if (!s.mapx && !s.mapy)
		{
			s.mapx = ft_atoi(line + 8)
			s.mapy = ft_atoi(line + 11)
		}
		free(line);
		ft_getmap(&s);
		//if (!get_direction(specs))
			//NO_SPACE = 1;
		set_piece(specs);
		if (ft_end(specs))
			break ;
	}
	return (0);
}
