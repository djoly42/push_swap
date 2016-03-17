/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:45:09 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 18:11:23 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putoctal_uintmax_t(uintmax_t nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal_uintmax_t(nbr / 8);
		ret = ret + ft_putoctal_uintmax_t(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

static int	ft_putoctal_hho(unsigned char nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal_hho(nbr / 8);
		ret = ret + ft_putoctal_hho(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

static int	ft_putoctal_ho(unsigned short int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal_ho(nbr / 8);
		ret = ret + ft_putoctal_ho(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

static int	ft_putoctal_llo(unsigned long long int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal_llo(nbr / 8);
		ret = ret + ft_putoctal_llo(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

static int	ft_putoctal_lo(unsigned long int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal_lo(nbr / 8);
		ret = ret + ft_putoctal_lo(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

static int	ft_putoctal_zo(size_t nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal_zo(nbr / 8);
		ret = ret + ft_putoctal_zo(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

static int	ft_putoctal(unsigned int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_putoctal(nbr / 8);
		ret = ret + ft_putoctal(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

int	ft_which_putoctal(t_env *env)
{

		 if (FNDFLAGS[7] == 1)
			return (ft_putoctal_uintmax_t((uintmax_t)ARG));
		else if (FNDFLAGS[5] == 1)
			return (ft_putoctal_ho((unsigned short int)ARG));
		else if (FNDFLAGS[5] == 2)
			return (ft_putoctal_hho((unsigned char)ARG));
		else if (FNDFLAGS[6] == 1)
			return (ft_putoctal_lo((unsigned long int)ARG));
		else if (FNDFLAGS[6] == 2)
			return (ft_putoctal_llo((unsigned long long int)ARG));
		else if (FNDFLAGS[8] == 1)
			return (ft_putoctal_zo((size_t)ARG));
		else
			return (ft_putoctal((unsigned int)ARG));
	//}
}
