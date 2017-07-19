/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:58:53 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/19 18:00:48 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int			get_all(t_struct *s)
{
	int		x;
	char	*line;

	x = 0;
	s->tmp = ft_memalloc(sizeof(char*) * 200);
	while(get_next_line(0, &line) > 0)
	{
		s->tmp[x] = line;
		x++;
	}
	x = 0;
	return (x);
}
