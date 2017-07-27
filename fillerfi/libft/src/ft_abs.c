/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:30:08 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/24 22:42:13 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

double	ft_dabs(double nb)
{
	return (nb < 0 ? -nb : nb);
}

float	ft_fabs(float nb)
{
	return (nb < 0 ? -nb : nb);
}

long	ft_labs(long nb)
{
	return (nb < 0 ? -nb : nb);
}
