/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:45:12 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/08 16:07:56 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct	s_struct
{
	char	**map;
	char	**piece;
	int		me;
	int		mex;
	int		mey;
	int		distmax;
	int		enemy;
	int 	enemyx;
	int		enemyy;
	int		piecex;
	int		piecey;
	int		mapx;
	int		mapy;
	int		dir;
	int		stop;
	int		x;
	int		y;
	int		distenemy;
}				t_struct;

void			ft_init_struct(t_struct *s);
int				ft_end(t_struct *s);
int				ft_get_enemy_play(t_struct *s);
int				strat_downright(t_struct *s);
int				strat_upleft(t_struct *s);
void			ft_print_piece(t_struct *s);
int				get_next_line(const int fd, char **line);
void			error(int i);

#endif
