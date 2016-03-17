
#include "ft_printf.h"


static void x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
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
		RET = RET + ft_putstr2((char *)ARG, NBRPREC);
	else
		RET = RET + ft_putstr((char *)ARG);
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

int     fonct_s(t_env *env)
{
//    if (FNDFLAGS[9] == 1 && NBRPREC == -1)
//		return (0);
if(FNDFLAGS[6] == 1)
{
fonct_S(env);
	return (1);
}
if(ARG != NULL)
ARGLEN = ft_strlen((char *)ARG);
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
    RET = RET + ft_putstr((char *)ARG);
    if (FNDFLAGS[2] == 1 && NBR > ARGLEN)
        RET = RET + ft_putspace(NBR - ARGLEN);
	}
	return (0);
}
