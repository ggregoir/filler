/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:13:57 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/27 23:56:55 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int fd = 0;

/*int		enemy_dist(t_struct *s, int x, int y)
{
	int		i;
	int		j;
	int		len;

	len = 0;
//	printf("SALUT\n");
	while (++len)
	{
		j = y - len;
		while (j <= y + len)
		{
			i = x - len;
			while (i <= x + len)
			{
				if (i >= 0 && j < s->mapy && j >= 0 && i < s->mapx)
					if (s->map[j][i] == s->enemy)
						return (len);
				i++;
			}
			j++;
		}
		//printf("len = %d\n", len);
	}
	//printf("IM OUT\n");
	return (s->distmax);
}

int			check(t_struct *s, int x, int y, int aste)
{
	int i;
	int j;

	j = -1;
	//printf("toast\n");
	while( j++ < s->piecey)
	{
		//printf("lel\n");
		i = -1;
		//printf("lil\n");
		while (i++< s->piecex)
		{
			//printf("lul\n");
			//printf("i = %d j = %d\n", i, j);
			if (i >= 0 && j >= 0 && j < s->piecey && i < s->piecex)
			{
				//printf("lal\n");
				//printf("i = %d j = %d\n", i, j);
				if (s->piece[j][i] == '*')
				{
					//printf("i = %d j = %d\n", i, j);
					if (j + y < 0 || i + x < 0 || j + y >= s->mapy ||
						i + x >= s->mapx)
					{
						return (0);
						//printf("lol1\n");
					}
					else if (s->map[j + y][i + x] == s->me)
						{
							//printf("yolo\n");
							aste++;
						}
					else if (s->map[j + y][i + x] == s->enemy)
					{
						return (0);
						//printf("lol2\n");
					}
					//printf("laikenf\n");
				}
				//printf("mom's swaggheti\n");
			}
			//printf("ameno\n");
		}
		//printf("why u do dis\n");
	}
	//printf("hehehehehehe\n");
	return ((aste == 1) ? enemy_dist(s, x, y) : 0);
}

int		strat_upleft(t_struct *s)
{
	printf("lelilel\n");
	int		x;
	int		y;
	int		ret;

	y = -s->piecey;
	while(y < s->mapy)
	{
		x = -s->piecex;
		while (x < s->mapx)
		{
			if ((ret = check(s, x, y, 0)))
			{
				if (ret < s->distenemy)
				{
					s->x = x;
					s->y = y;
					s->distmax = ret;
				}
			}
			x++;
		}
		y++;
	}

	return ((s->distenemy < s->distmax) ? 1 : 0);
}

int		strat_downright(t_struct *s)
{
	//printf("lolilol\n");
	int		x;
	int		y;
	int		ret;

	y = s->mapy + s->piecey;
	//printf("y = %d\n",y );
	while(y > -s->mapy)
	{
		x = s->mapx + s->piecex;
		//printf("x = %d\n",x );
		while (x > -s->mapx)
		{
			if ((ret = check(s, x, y, 0)))
			{
				if (ret < s->distenemy)
				{
					s->x = x;
					s->y = y;
					s->distmax = ret;
				}
			}
			x--;
		}
		y--;
	}
	return ((s->distenemy < s->distmax) ? 1 : 0);
}
*/
int	place_piece(t_struct *s, int yi, int xi)
{
	int		i;
	int		j;
	int 	x;
	int 	y;
	int		nb;

	if (fd == 0)
		fd = open("/dev/ttys001", O_WRONLY);

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
				x = x + xi;
				if (y >= s->mapy || x >= s->mapx || !can_place(s, x, y, &nb))
					return (0);
			}
		}
	}
	return (nb == 1);
}

void			get_strat(t_struct *s)
{
	int		curr;
	int		best;
	int 	x;
	int 	y;

	if (fd == 0)
		fd = open("/dev/ttys001", O_WRONLY);

	best = 1024;
	y = -1 - s->stary;
	while (++y < s->mapy)
	{
		x = -1 - s->starx;
		while (++x < s->mapx)
		{
			//ft_putendl_fd(ft_itoa(x), fd);
			//ft_putendl_fd(ft_itoa(y), fd);
			if (place_piece(s, x, y))
			{
				//ft_putendl_fd("lol", fd);
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
