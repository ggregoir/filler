/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:10:10 by ggregoir          #+#    #+#             */
/*   Updated: 2017/06/21 23:30:02 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	char *ret;

	if ((str = (char *)malloc(sizeof(*str) * size + 1)) == NULL)
		return (NULL);
	ft_bzero((void*)str, size);
	str[size] = '\0';
	ret = str;
	ft_strdel(&str);
	return (ret);
}
