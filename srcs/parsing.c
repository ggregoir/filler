/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:58:53 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/22 02:57:34 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>


int			get_all(t_struct *s)
{
	int		x;
	char	*line;
	int ret;

	x = 0;
	while((ret = (get_next_line(0, &line)) > 0))
	{
		s->tmp[x] = line;
		x++;
	}
	return (x);
}
