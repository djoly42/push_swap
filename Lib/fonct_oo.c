/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_oo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 11:12:20 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puttest(unsigned long int nbr)
{
	int	ret;

	ret = 0;
	if (nbr > 7)
	{
		ret = ret + ft_puttest(nbr / 8);
		ret = ret + ft_puttest(nbr % 8);
	}
	else
	{
		ret = ret + ft_putchar(nbr + '0');
	}
	return (ret);
}

static int		ft_nbrlenO(unsigned long int nb)
{
	int i;

	i = 1;
	while (nb /= 8)
		i++;
	return (i);
}

static unsigned long int     ft_octalnbr(unsigned long int nb)
{
    if (nb > 7)
        return ((nb % 8) + 10 * ft_octalnbr(nb / 8));
    return (nb);
}

static unsigned long int     ft_octaluint_t(unsigned long int nb)
{
    if (nb > 7)
        return ((nb % 8) + 10 * ft_octaluint_t(nb / 8));
    return (nb);
}

static void x_prec(t_env *env)
{
	if (NBRPREC != -1 )
	{
		if (FNDFLAGS[2] != 1 && NBR > ARGLEN &&  NBRPREC < ARGLEN )
			RET = RET + ft_putspace(NBR - ARGLEN);
		else if (FNDFLAGS[2] != 1 && NBR > ARGLEN &&  NBRPREC < NBR )
	    	RET = RET + ft_putspace(NBR - NBRPREC);
		if (NBRPREC > env->arglen )//.
			RET = RET + ft_putzero2(NBRPREC - env->arglen);
		RET = RET + ft_puttest((unsigned long int)ARG);
		if (FNDFLAGS[2] == 1 && FNDFLAGS[9] == 1 && NBR > NBRPREC)// -
			RET = RET + ft_putspace(NBR - NBRPREC);
	}
	else if(NBR != -1)
	{
		if (FNDFLAGS[0] == 1)
		{
			if ((unsigned long int)ARG != 0)
			{
				RET = RET + ft_putspace(NBR - 1 - ARGLEN);
				RET = RET + ft_putchar('0');
			}
			else
				RET = RET + ft_putspace(NBR - 1);
			RET = RET + ft_puttest((unsigned long int)ARG);
		}
		else
			RET = RET + ft_putspace(NBR);
	}
	else if (FNDFLAGS[0] == 1)
	{
		if ((unsigned long int)ARG != 0)
			RET = RET + ft_putchar('0');
		RET = RET + ft_puttest((unsigned long int)ARG);
	}
}



int                     fonct_O(t_env *env)
{
	env->arglen = ft_nbrlenO(ft_octalnbr((unsigned long int)ARG));
/*
	ft_putstr(">>ret02>>");
	ft_putnbr(ARGLEN);
	ft_putstr("<<");
*/
	if (FNDFLAGS[9] == 1)
		x_prec(env);
	else
	{

		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR != -1) // pas de - et nbr pas de 0
		{
			if (FNDFLAGS[0] == 1)
			NBR = NBR - 1;
			RET = RET + ft_putspace(NBR - env->arglen);
		}

		if (FNDFLAGS[2] != 1 && FNDFLAGS[1] == 1 && NBR != -1)
		RET = RET + ft_putzero2(NBR - env->arglen);
		if (FNDFLAGS[0] == 1)
		RET = RET + ft_putzero2(1);
		if (FNDFLAGS[7] == 1)
			RET = RET + ft_puttest((unsigned long int)ARG);//RET = RET + ft_puttest((long int)ARG);
		else
			RET = RET + ft_puttest((unsigned long int)ARG);
	//	 ft_putnbr(RET);

		if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen) // - et nbr
		{
			if (FNDFLAGS[0] == 1)
			NBR = NBR - 1;
			RET = RET + ft_putspace(NBR - env->arglen);
		}
	}
    //ft_putnbr(RET);
return (1);
}
