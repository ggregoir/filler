/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 19:45:12 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/27 22:14:04 by ggregoir         ###   ########.fr       */
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
	int		enemy;
	int		piecex;
	int		piecey;
	int		mapx;
	int		mapy;
	int		stop;
	int		x;
	int		y;
	char	**tmp;
	int		starx;
	int		stary;
}				t_struct;

typedef struct		s_line
{
	char			*tab;
	int				fd;
	struct s_line	*next;
}					t_line;

void			ft_init_struct(t_struct *s);
int				ft_end(t_struct *s);
int				ft_get_enemy_play(t_struct *s);
int				strat_downright(t_struct *s);
int				strat_upleft(t_struct *s);
void			ft_print_piece(t_struct *s);
int				get_all(t_struct *s);
int				get_next_line(const int fd, char **line);
void			error(int i);
char			*ft_strjoin_and_free(char *s1, char *s2, char c, int at);
size_t			ft_strlenchr(const char *s, char c);
void			parse_piece(t_struct *s);
int				can_place(t_struct *s, int x, int y, int *nb);
void			get_star(t_struct *s);
int				get_best_cell(t_struct *s, int yi, int xi);
void			get_strat(t_struct *s);
int				cell_type(t_struct *s, char cell);

#endif
