/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:31:29 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:14 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsuffix(const char *str, const char *suffix)
{
	int		i;

	if (!str)
		return (0);
	if (!suffix)
		return (1);
	i = ft_strlen(str) - ft_strlen(suffix);
	if (i < 0)
		return (0);
	while (str[i] && str[i] == *suffix++)
		i++;
	return (str[i] == '\0' ? 1 : 0);
}
