/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_dd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:22:30 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 13:59:22 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nbrlenD(long int nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

static int		ft_nbrlenhhD(unsigned char nb)
{
	int i;

	i = 1;
	while (nb /= 10)
		i++;
	return (i);
}

int				ft_arglenD(t_env *env)
{
	//if (FNDFLAGS[6] == 1)
	//	return (ft_nbrlenl((long unsigned int)ARG));
	//else if (FNDFLAGS[6] == 2)
	//	return (ft_nbrlenll((long long unsigned int)ARG));
	//else if (FNDFLAGS[7] == 1)
	//	return (ft_nbrlenj((uintmax_t)ARG));
	//else
	 if (FNDFLAGS[5] == 2)
		return (ft_nbrlenhhD((unsigned char)ARG));
	else
		return (ft_nbrlenD((long int)ARG));
}

/*
int	ft_putnbrhhD(int nbr)
{
	int	ret;

	ret = 0;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
    if (nbr == -9223372036854775808)
    {
		ft_putstr("-9223372036854775808");
		return (20);
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = (-1) * nbr;
			ret++;
		}
		if (nbr >= 10)
		{
			ret = ret + ft_putnbrhhD(nbr / 10);
			ret = ret + ft_putnbrhhD(nbr % 10);
		}
		else
		{
			ret = ret + ft_putchar(nbr + '0');
		}
	}
	return (ret);
}
*/

void			ft_which_putnbrD(t_env *env)
{


	if (FNDFLAGS[5] == -1 && FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1 && FNDFLAGS[8] == -1 && (int)ARG < 0)//          (long long int)ARG < 9223372036854775808)//  (long long int)ARG < 0 )//&& FNDFLAGS[2] != 1) // - nest pas encore ecrie, voir putzero
	{
		//ft_putstr(">>DANS IF1>>");
		RET = RET + ft_putnbr((long int)ARG);//pos);
	}
	else if(FNDFLAGS[6] == 1)
	{
		//ft_putstr(">>DANS IF2>>");
		RET = RET + ft_putnbr((long int)ARG);
	}
	else if(FNDFLAGS[6] == 2)
	{
		//    printf(">>%lld<<",ARG);
		//ft_putstr(">>DANS IF3>>");
		RET = RET + ft_putnbr((long long int)ARG);
	}
	else if(FNDFLAGS[8] == 1)
	{
		//	ft_putstr(">>DANS Z>>");
		RET = RET + ft_putnbr((size_t)ARG);
	}
	else if(FNDFLAGS[5] == 2)
	{
		//ft_putstr(">>DANS IF5>>");
		RET = RET + ft_putnbr((int)ARG);
	}
	else if(FNDFLAGS[7] == 1)
	{
		//ft_putstr(">>DANS J>>");
		RET = RET + ft_putnbr((intmax_t)ARG);
	}
	else if(FNDFLAGS[5] == 1)
	{
		//ft_putstr(">>DANS H>>");
		RET = RET + ft_putnbr((int)ARG);
	}
	else
	{
		//	ft_putstr(">>DANS ELSE>>");
		RET = RET + ft_putnbr((long int)ARG);
	}
}
