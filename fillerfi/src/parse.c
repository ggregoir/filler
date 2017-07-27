/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:09:10 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/27 15:19:27 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	parse_piece_size(t_env *e)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		tmp = ft_strchr(line, ' ');
		e->piece.y = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->piece.x = ft_atoi(++tmp);
		free(line);
	}
}

static void	parse_piece(t_env *e, char map[e->map.y][e->map.x])
{
	char	piece[e->piece.y][e->piece.x];
	char	*line;
	t_pos	idx;

	idx.y = -1;
	e->star = set_position(BIG_SIZE, BIG_SIZE);
	while (++idx.y < e->piece.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			idx.x = -1;
			while (++idx.x < e->piece.x)
			{
				if (line[idx.x] == '*' && e->star.y > idx.y)
					e->star.y = idx.y;
				if (line[idx.x] == '*' && e->star.x > idx.x)
					e->star.x = idx.x;
				piece[idx.y][idx.x] = line[idx.x];
			}
			free(line);
		}
	}
	get_placement(e, map, piece);
}

static int	make_img(t_env *e, t_img *img)
{
	if (!(img->i = mlx_new_image(e->mlx, e->map.x * 10, e->map.y * 10)))
		return (ERROR);
	img->d = mlx_get_data_addr(img->i, &(img->bpp), &(img->sl), &(img->edn));
	return (SUCCESS);
}

int			parse_map_size(char *line, t_env *e)
{
	char	*tmp;
	char	*tmp2;
	char	*s;

	if (!ft_strncmp(line, "Plateau", 7))
	{
		tmp = ft_strchr(line, ' ');
		e->map.y = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		e->map.x = ft_atoi(++tmp);
		tmp = ft_strjoin("P1 (", e->player == 'O' ? "red)" : "blue)");
		tmp2 = ft_strjoin(" vs P2 (", e->player == 'X' ? "red)" : "blue)");
		s = ft_strjoin(tmp, tmp2);
		if (!(e->win = mlx_new_window(e->mlx, e->map.x * 10, e->map.y * 10, s))
		|| !(make_img(e, &(e->img))))
			return (ERROR);
		free(tmp);
		free(tmp2);
		free(s);
		mlx_expose_hook(e->win, display_graph, e);
		mlx_hook(e->win, X_EVENT, X_MASK, delete_win, e);
		return (SUCCESS);
	}
	return (ERROR);
}

void		parse_map(t_env *e)
{
	char	map[e->map.y][e->map.x];
	char	*line;
	t_pos	idx;

	idx.y = -1;
	while (++idx.y < e->map.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			idx.x = -1;
			while (++idx.x < e->map.x)
				map[idx.y][idx.x] = line[idx.x + 4];
			free(line);
		}
	}
	parse_piece_size(e);
	parse_piece(e, map);
}
