/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:26:18 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/07/02 15:27:02 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void			ft_error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
