/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:09:51 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 11:45:30 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbru(nbr / 10);
		ret = ret + ft_putnbru(nbr % 10);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

int	ft_putnbrhu(uintmax_t nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbrhu(nbr / 10);
		ret = ret + ft_putnbrhu(nbr % 10);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

int	ft_putnbrhhu(unsigned char nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbrhu(nbr / 10);
		ret = ret + ft_putnbrhu(nbr % 10);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

int	ft_putnbrllu(long long unsigned nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbrllu(nbr / 10);
		ret = ret + ft_putnbrllu(nbr % 10);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

int	ft_putnbrlu(long unsigned nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbrlu(nbr / 10);
		ret = ret + ft_putnbrlu(nbr % 10);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

int	ft_putnbrzu(size_t nbr)
{
	int	ret;

	ret = 0;
	if (nbr >= 10)
	{
		ret = ret + ft_putnbrzu(nbr / 10);
		ret = ret + ft_putnbrzu(nbr % 10);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

int	ft_which_putnbr(t_env *env)
{
	if (ITOK == 8 || ITOK == 9)
	{
		if (FNDFLAGS[6] == 1)
			return (ft_putnbrlu((long unsigned int)ARG));
		else if (FNDFLAGS[6] == 2)
			return (ft_putnbrllu((long long unsigned int)ARG));
		else if (FNDFLAGS[7] == 1)
			return (ft_putnbrhu((uintmax_t)ARG));
		else if (FNDFLAGS[5] == 1 || ITOK == 9)
			return (ft_putnbrhu((uintmax_t)ARG));
		else if (FNDFLAGS[5] == 2)
			return (ft_putnbrhhu((unsigned char)ARG));
		else if (FNDFLAGS[8] == 1)
			return (ft_putnbrzu((size_t)ARG));
		else
			return (ft_putnbru((unsigned int)ARG));
	}
}

int	ft_putnbr2(long long unsigned int nbr)
{
	int	ret;

	ret = 0;
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
			ret++;
		}
		if (nbr >= 10)
		{
			ret = ret + ft_putnbr2(nbr / 10);
			ret = ret + ft_putnbr2(nbr % 10);
		}
		else
		{
			ret = ret + ft_putchar(nbr + '0');
		}
	//}
	return (ret);
}


int	ft_putnbr(long long int nbr)
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
			ret = ret + ft_putnbr(nbr / 10);
			ret = ret + ft_putnbr(nbr % 10);
		}
		else
		{
			ret = ret + ft_putchar(nbr + '0');
		}
	}
	return (ret);
}
