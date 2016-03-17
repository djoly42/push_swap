/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:00:07 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 15:36:57 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_wnstrlen(wchar_t *str, int n)
{
	int i;

	i = 0;
	while (*str != '\0' && (i + ft_wcharlen(*str)) <= n)
	{
		i += ft_wcharlen(*str);
		str++;
	}
	return (i);
}

static void x_prec(t_env *env)
{

/*
	ft_putstr("ARGLEN==");
	ft_putnbr(ARGLEN);
	ft_putstr("<<<");

	ft_putstr("NBR==");
	ft_putnbr(NBR);
	ft_putstr("<<<");
*/
	if (NBRPREC != -1)
	{
		NBRPREC = ft_wnstrlen((wchar_t *)ARG, NBRPREC);
	if (FNDFLAGS[2] == -1 && NBR != -1)// && NBRPREC != -1) //pas de - et nbr
	{
		if (NBRPREC > ARGLEN && NBR > ARGLEN)
		{
		if (FNDFLAGS[1] == 1)
			RET = RET + ft_putzero2(NBR - ARGLEN);
		else
			RET = RET + ft_putspace(NBR - ARGLEN);
		}
		else if (NBRPREC != -1 && NBR > NBRPREC)
		{
		if (FNDFLAGS[1] == 1)
			RET = RET + ft_putzero2(NBR - NBRPREC);
		else
			RET = RET + ft_putspace(NBR - NBRPREC);
		}
	}
	if (FNDFLAGS[9] == 1 && NBRPREC != -1)
		RET = RET + ft_putwnstr((wchar_t *)ARG, NBRPREC);
	else
		RET = RET + ft_putwstr((wchar_t *)ARG);
	if (FNDFLAGS[2] == 1 && NBR != -1 && NBRPREC != -1)
	{
		if (NBRPREC > ARGLEN)
			RET = RET + ft_putspace(NBR - ARGLEN);
		else
			RET = RET + ft_putspace(NBR - NBRPREC);
	}
	}
	else
	{
		//ft_putstr(">>");
		if (FNDFLAGS[1] == 1)
			RET = RET + ft_putzero2(NBR);
		else
			RET = RET + ft_putspace(NBR);

	}
}

int     fonct_S(t_env *env)
{
//    if (FNDFLAGS[9] == 1 && NBRPREC == -1)
//		return (0);
if(ARG != NULL)
	ARGLEN = ft_wstrlen((wchar_t *)ARG);
if (FNDFLAGS[9] == 1)
	x_prec(env);
else
{

	if (ARG == NULL)
    {
     RET += ft_putstr("(null)");
     return (0);
    }

    if (FNDFLAGS[2] == -1 && NBR > ARGLEN) //pas de - et nbr
    {
        if (FNDFLAGS[1] == 1)
            RET = RET + ft_putzero2(NBR - ARGLEN);
        else
            RET = RET + ft_putspace(NBR - ARGLEN);
    }
    RET = RET + ft_putwstr((wchar_t *)ARG);
    if (FNDFLAGS[2] == 1 && NBR > ARGLEN)
        RET = RET + ft_putspace(NBR - ARGLEN);
	}
	return (0);
}
