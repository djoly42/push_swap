/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:59:32 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 12:08:23 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlenh(unsigned short int nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

int		ft_nbrlenl(long unsigned int nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}



int		ft_nbrlenj(uintmax_t nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

int		ft_nbrlenll(long long unsigned int nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}
int		ft_unbrlen(unsigned int nb)
{
	int i;

    i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

int		ft_nbrlen(int nb)
{
	int i;

    i = 1;
    if (nb < 0)
    {
        i++;
        nb = -nb;
    }
	while (nb /= 10)
		i++;
	return (i);
}
