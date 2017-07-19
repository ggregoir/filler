/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:23:07 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/19 16:30:22 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_free_grid(void ***grid)
{
	int	i;

	i = 0;
	if (grid == NULL)
		return ;
	while (*grid[i] != NULL)
	{
		ft_strdel(*grid[i]);
		i++;
	}
	//ft_strdel(*grid);
	*grid = NULL;
}
