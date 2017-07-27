/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:41:12 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:14 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strprefix(const char *str, const char *prefix)
{
	if (!str)
		return (0);
	if (!prefix)
		return (1);
	while (*str && *prefix && *str == *prefix)
	{
		str++;
		prefix++;
	}
	return (!(*prefix));
}
