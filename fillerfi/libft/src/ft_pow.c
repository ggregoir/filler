/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:27:52 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int nb, int pow)
{
	if (nb == 0 || pow < 0)
		return (0);
	else if (pow == 0)
		return (1);
	else if (pow == 1)
		return (nb);
	return (nb * ft_pow(nb, pow - 1));
}