/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:58:53 by ggregoir          #+#    #+#             */
/*   Updated: 2017/07/24 21:28:38 by ggregoir         ###   ########.fr       */
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

size_t		ft_strlenchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin_and_free(char *s1, char *s2, char c, int at)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlenchr(s2, c);
	if (!(ret = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != c)
		ret[j++] = s2[i++];
	ret[j] = '\0';
	if (at == 1 || at == 3)
		ft_strdel(&s1);
	if (at == 2 || at == 3)
		ft_strdel(&s2);
	return (ret);
}

void		error(int i)
{
	i++;
}
