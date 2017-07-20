/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:13:57 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/20 13:39:08 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int		enemy_dist(t_struct *s, int x, int y)
{
	int		i;
	int		j;
	int		len;

	len = 0;
	while (++len)
	{
		i = y - len;
		while (i <= y + len)
		{
			j = x - len;
			while (j <= x + len)
			{
				if (j >= 0 && i < s->mapy && i >= 0 && j < s->mapx)
					if (s->map[i][j] == s->enemy)
						return (len);
				j++;
			}
			i++;
		}
	}
	return (s->distmax);
}

int			check(t_struct *s, int x, int y, int z)
{
	int i;
	int j;

	i = 0;
	//printf("toast\n");
	while( i < s->piecey)
	{
		//printf("lel\n");
		j = 0;
		i++;
		//printf("lil\n");
		while (j < s->piecex)
		{
			//printf("lul\n");
			if (i >= 0 && j >= 0 && i < s->piecey && j < s->piecex)
			{
			//	printf("lal\n");
			//	printf("i = %d j = %d\n", i, j);
				if (s->piece[i][j] == '*')
				{
					//printf("i = %d j = %d\n", i, j);
					if (i + y < 0 || j + x < 0 || i + y >= s->mapy ||
						j + x >= s->mapx)
					{
						return (0);
						//printf("lol1\n");
					}
					else if (s->map[i + y][j + x] == s->me)
						{
							//printf("yolo\n");
							z++;
						}
					else if (s->map[i + y][j + x] == s->enemy)
					{
						return (0);
						//printf("lol2\n");
					}
					//printf("laikenf\n");
				}
				//printf("mom's swaggheti\n");
			}
			//printf("ameno\n");
			j++;
		}
		//printf("why u do dis\n");
	}
	//printf("hehehehehehe\n");
	return ((z == 1) ? enemy_dist(s, x, y) : 0);
}

int		strat_upleft(t_struct *s)
{
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
	int		x;
	int		y;
	int		ret;

	y = s->mapy + s->piecey;
	while(y > s->mapy)
	{
		x = s->mapx + s->piecex;
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

