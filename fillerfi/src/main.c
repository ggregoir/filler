/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:32:25 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/27 14:49:39 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	filler_loop(void *env)
{
	t_env	*e;
	char	*line;
	char	*skip_line;

	e = (t_env*)env;
	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strncmp(line, "Plateau", 7))
		{
			if ((!e->map.y || !e->map.x) && !parse_map_size(line, e))
				return (ERROR);
			if (get_next_line(0, &skip_line) > 0)
				free(skip_line);
			parse_map(e);
		}
		free(line);
	}
	return (SUCCESS);
}

int			main(void)
{
	char	*line;
	t_env	e;

	if (!(e.mlx = mlx_init()))
	{
		return (ERROR);
		ft_putendl_fd("Creation of mlx failed.", 2);
	}
	e.map = set_position(0, 0);
	if (get_next_line(0, &line) > 0)
	{
		e.player = (line[10] == '1' ? 'O' : 'X');
		free(line);
	}
	mlx_loop_hook(e.mlx, filler_loop, &e);
	mlx_loop(e.mlx);
	return (0);
}
