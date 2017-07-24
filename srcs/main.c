/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 16:29:27 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/24 21:53:21 by ggregoir         ###   ########.fr       */
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
		free(line);
	}
}

void			ft_getpiece(t_struct *s)
{
	int fd = 0;
	if (fd == 0)
		fd = open("/dev/ttys001", O_WRONLY);
	char 		*line;
	int			i;

	get_next_line(0, &line);
	ft_putendl_fd("avant", fd);
	s->piecey = ft_atoi(line + 6);
	s->piecex = ft_atoi(line + 8);
	//ft_putendl_fd(ft_itoa(s->piecey), fd);
	//ft_putendl_fd(ft_itoa(s->piecex), fd);
	s->piece = ft_memalloc(sizeof(char*) * s->piecey);
	i = -1;
	while(i++ <= (s->piecey - 2))
	{
		if (get_next_line(0, &line) > 0)
		{
			s->piece[i] =line;
			ft_putendl_fd(s->piece[i], fd);
			//free(line);
		}
		ft_putendl_fd("lolilolilol", fd);
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
	int fd = 0;
	if (fd == 0)
		fd = open("/dev/ttys001", O_WRONLY);
ft_putendl_fd("avant", fd);
	s->map = ft_memalloc(sizeof(char*) * s->mapy);
	ft_putendl_fd("lel", fd);
	get_next_line(0, &line);
	ft_putendl_fd("lul", fd);
	if (line[4] == 0)
		get_next_line(0, &line);
	ft_putendl_fd("lal", fd);
	i = 0;
	while(i < s->mapy )
	{
		if (get_next_line(0, &line) > 0)
		{
			//ft_putendl_fd("lol", fd);
			if (!(s->map[i] = ft_strdup(line + 4)))
				error(2);
			ft_putendl_fd(s->map[i], fd);
			free(line);
		}
		i++;
	}
	ft_putendl_fd("apres boucle", fd);
	i = 0;
	ft_getpiece(s);
	ft_putendl_fd("apres", fd);
	if (s->enemyx == 0 && s->enemyy == 0 && s->mex == 0 && s->mey == 0)
		ft_getinitpos(s);

}

int 			main()
{
	t_struct	s;
	char 		*line;
	int fd = 0;
	if (fd == 0)
		fd = open("/dev/ttys001", O_WRONLY);

	ft_init_struct(&s);
	ft_getplayers(&s);
	while (get_next_line(0, &line) > 0)
	{
		if (!s.mapx && !s.mapy)
		{
			s.mapy = ft_atoi(line + 8);
			s.mapx = ft_atoi(line + 11);
		}
		//printf("player = %c mapx = %d mapy = %d piecex = %d piecey = %d mex = %d mey = %d enemyx = %d enemyy = %d  \n", s.me,s.mapx, s.mapy, s.piecex, s.piecey, s.mex, s.mey, s.enemyx, s.enemyy);

		free(line);
		ft_putendl_fd("boucle", fd);
		ft_getmap(&s);
		ft_putendl_fd("here ?", fd);
		ft_putendl_fd(ft_itoa(s.mapy), fd);
		ft_putendl_fd(ft_itoa(s.mapx), fd);
		if (!ft_get_enemy_play(&s))
			s.stop = 1;
		ft_putendl_fd("there ?", fd);
		ft_print_piece(&s);
		if (ft_end(&s))
		{
			ft_putendl_fd("wrong", fd);
			break ;
		}
	}
	return (0);
}
