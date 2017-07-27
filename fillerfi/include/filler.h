/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:40:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/27 15:50:15 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
**  Not much to explain here...
*/

# include <libft.h>
# include <mlx.h>

/*
**  An event and his mask for the generic hook system function for all events
**  called mlx_hook(...) (see prototype in mlx.h)
*/

# define X_MASK (1L<<4)
# define X_EVENT 4

/*
**  Macros that are not very usefull but makes the code clearer... in my opinion
*/

# define ERROR 0
# define SUCCESS 1

/*
**  BIG_SIZE is used to initialise a t_pos var in order to compare with
**  the current one
*/

# define BIG_SIZE 1000000000
# define NS_SIZE -100
# define LOWCASE 32

/*
**  a structure for the position of an element. Also used as parsing index
**  in a double array map
*/

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

/*
**  a structure for a graphical image with minilibx.
**  i => image, d => data, bpp => bits per pixel, sl => size_line
**  edn => endian wich is a sequential order of bytes in computer memory
**  depending on the most and least significant bit (big-endian / little-endian)
**  Although this var is completely useless on MAC OS
*/

typedef struct	s_img
{
	void		*i;
	char		*d;
	int			bpp;
	int			sl;
	int			edn;
}				t_img;

/*
**  The core structure of this program, all variables names are self explanatory
**  mlx and win are the tools for graphical representation with minilibx
**  mlx is a mandatory pointer for every function in mlx library.
**  win => window
**  img => image
**  sorry for stating the obvious...
*/

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		player;
	t_pos		map;
	t_pos		piece;
	t_pos		star;
	t_pos		best;
}				t_env;

/*
**  Prototypes with self explanatory names...
**  pos => position, dist => distance
*/

int				parse_map_size(char *line, t_env *e);
void			parse_map(t_env *e);

void			get_placement(t_env *e, char map[e->map.y][e->map.x], \
						char piece[e->piece.y][e->piece.x]);

t_pos			set_position(int x, int y);
int				get_distance(t_pos a, t_pos b);
int				cell_type(t_env *e, char cell);
void			put_position(t_env *e, t_pos p);
int				delete_win(void *env);

int				display_graph(void *env);
void			make_graph(t_env *e, char map[e->map.y][e->map.x]);

#endif
