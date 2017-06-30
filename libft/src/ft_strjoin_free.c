/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:56:40 by ggregoir          #+#    #+#             */
/*   Updated: 2017/03/13 13:23:14 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int flag)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (flag == 1)
		ft_strdel((char**)&s1);
	if (flag == 2)
		ft_strdel((char**)&s2);
	if (flag == 3)
	{
		ft_strdel((char**)&s1);
		ft_strdel((char**)&s2);
	}
	return (str);
}
