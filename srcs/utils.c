/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 19:04:20 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/31 19:25:07 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>


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
	ft_putnbr(s->x);
	ft_putchar(' ');
	ft_putnbr(s->y);
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
}
