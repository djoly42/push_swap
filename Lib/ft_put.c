/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 11:48:11 by djoly             #+#    #+#             */
/*   Updated: 2016/02/18 11:06:53 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putzero2(int nbr)
{
	int i;

	i = -1;
	while (++i < nbr)
	 ft_putchar('0');
	 return (nbr);
}

int	ft_putspace(int nbr)
{
	int i;

	i = -1;
	while (++i < nbr)
		ft_putchar(' ');
	return (nbr);
}
