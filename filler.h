/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:45:12 by ggregoir          #+#    #+#             */
/*   Updated: 2017/06/30 21:05:14 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"


#define DOWNRIGHT = 1;

typedef struct	s_struct
{
	char	**map
	char	**piece
	int		me;
	int		mex;
	int		mey
	int		enemy;
	int 	enemyx;
	int		enemyy;
	int		piecex;
	int		piecey;
	int		mapx;
	int		mapy;
	int		dir;
}				t_struct;

#endif
