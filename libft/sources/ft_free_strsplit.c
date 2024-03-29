/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:22:53 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/06/30 19:22:36 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_free_strsplit(char *s, char **buff, char split)
{
	int x;
	int len;

	len = ft_count_words(s, split);
	x = -1;
	while (++x < len)
		free(buff[x]);
	free(buff);
}
