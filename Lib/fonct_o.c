/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:03:36 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 09:34:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static unsigned long int     ft_octalnbr(unsigned long  int nb)
{
    if (nb > 7)
        return ((nb % 8) + 10 * ft_octalnbr(nb / 8));
    return (nb);
}

static unsigned long int     ft_octaluint_t(unsigned long  int nb)
{
    if (nb > 7)
        return ((nb % 8) + 10 * ft_octaluint_t(nb / 8));
    return (nb);
}

static int		ft_nbrlenhho(unsigned char nb)
{
	int i;

	i = 1;
	while (nb /= 8)
		i++;
	return (i);
}


static int		ft_nbrleno(unsigned long int nb)
{
	int i;

	i = 1;
	while (nb /= 8)
		i++;
	return (i);
}
static int	ft_arglen(t_env *env)
{
	if (FNDFLAGS[5] == 2)
		return (ft_nbrlenhho((unsigned char)ARG));
	else if (FNDFLAGS[6] == 2)
		return (ft_nbrlenll((long long unsigned int)ARG));
	else if (FNDFLAGS[7] == 1)
		return (ft_nbrlenj((uintmax_t)ARG));
	else if (FNDFLAGS[5] == 1)
		return (ft_nbrlenh((uintmax_t)ARG));
	else
		return (ft_nbrleno((unsigned int)ARG));
}



static void x_prec(t_env *env)
{
	if (NBRPREC != -1 )
	{

		if (FNDFLAGS[2] == -1 && NBR > ARGLEN &&  NBRPREC < ARGLEN )
			RET = RET + ft_putspace(NBR - ARGLEN);
		else if (FNDFLAGS[2] == -1 && NBR > ARGLEN &&  NBRPREC < NBR )
	    	RET = RET + ft_putspace(NBR - NBRPREC);
		if (NBRPREC > env->arglen )//.
			RET = RET + ft_putzero2(NBRPREC - env->arglen);
		//ft_putstr(">>");
		RET = RET + ft_which_putoctal(env);
		//ft_putstr("<<");
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
			//ft_putstr(">>");
			RET = RET + ft_which_putoctal(env);
			//ft_putstr("<<");
		}
		else
			RET = RET + ft_putspace(NBR);
	}
	else if (FNDFLAGS[0] == 1)
	{
		if ((unsigned long int)ARG != 0)
			RET = RET + ft_putchar('0');
		RET = RET + ft_which_putoctal(env);
	}
}

int                     fonct_o(t_env *env)
{
	ARGLEN = ft_arglen(env);
	//ft_putnbr(env->arglen);
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
		if (FNDFLAGS[0] == 1 && (unsigned long int)ARG != 0)
		RET = RET + ft_putzero2(1);
		RET = RET + ft_which_putoctal(env);
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
