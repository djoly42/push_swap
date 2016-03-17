
#include "ft_printf.h"


static void ft_putzero(t_env *env)
{
	int i;

	if ((int)ARG < 0 &&  env->putneg!= 1)
	{
		RET = RET + ft_putchar('-');
		ARG = (-1) * (int)env->arg;
		NBR = NBR - 1;
		env->putneg = 1;
	}
	if (NBR != -1)
	NBR = NBR - ft_nbrlen((int)ARG);
	i = -1;
	while (++i < (NBR))
	RET = RET + ft_putchar('0');
	/*
	ft_putstr(">>ret02>>");
	ft_putnbr(RET);
	ft_putstr("<<");
	*/
}

static void     ft_flag_prec(t_env *env)
{
	int pos;

	//statut(env);
	if ((long int)ARG == 0 && NBR == -1 && NBRPREC == -1)//
		return ;
	if (NBRPREC == -1 && NBRPREC < ARGLEN && (long int)ARG != 0)
		NBRPREC = ARGLEN;
	if (NBR >= ARGLEN && NBR > NBRPREC && FNDFLAGS[2] != 1) // nbr sans -
	{
		if (FNDFLAGS[3] == 1) // +
		NBR = NBR - 1;
		if ((long int)ARG < 0 && ARGLEN < NBRPREC)
		NBR = NBR - 1;
		if (NBRPREC > ARGLEN) //!= -1)
		RET = RET + ft_putspace(NBR - NBRPREC);
		else if ((long int)ARG == 0 && NBRPREC == -1)
		RET = RET + ft_putspace(NBR);
		else
		RET = RET + ft_putspace(NBR - ARGLEN);
	}
	if (FNDFLAGS[3] == 1) // +
	RET = RET + ft_putchar('+');
	if (NBRPREC >= ARGLEN)
	{
		if ((long int)ARG < 0 && env->putneg != 1)
		{
			RET = RET + ft_putchar('-');
			ARG = (-1) * (long int)env->arg;
			//if (NBR != -1)
			NBR = NBR - 1;
			env->putneg = 1;

		}
		//if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1)
		//{
			if (NBRPREC == ARGLEN && env->putneg == 1)
			RET = RET + ft_putzero2(1);
			else if (NBRPREC > ARGLEN && env->putneg == 1)
			RET = RET + ft_putzero2(NBRPREC - ARGLEN + 1);
			else
			RET = RET + ft_putzero2(NBRPREC - ARGLEN);
		//}
		//		ft_putstr(">>putzero<<");
	}
	if (NBRPREC != -1)
	{
		ft_which_putnbrD(env);
	}
	if (NBR != -1 && FNDFLAGS[2] == 1)
	{
		if (FNDFLAGS[3] == 1) // +
		NBR = NBR - 1;
		RET = RET + ft_putspace(NBR - NBRPREC);
	}
}


int     fonct_D(t_env *env)
{
	int	pos;

	ARGLEN = ft_arglenD(env);
/*
	ft_putstr(">>RET2>>");
	ft_putnbr(ARGLEN);
	ft_putstr("<<");
*/
	if (FNDFLAGS[9] == 1)//.
	ft_flag_prec(env);
	else
	{
		if(FNDFLAGS[2] != 1) // pas de -
		{
			if (FNDFLAGS[4] == 1 && NBR == -1 && FNDFLAGS[3] == -1 && ((long int)ARG > 0)) // ' ' pas de NBR
			{
				RET = RET + ft_putchar(' ');
			}
			else if (FNDFLAGS [1] == -1 && NBR != -1 && NBR > ARGLEN)// pas de 0  nbr > arg
			{
				if (FNDFLAGS[3] == 1 && (long int)ARG > 0)
				NBR = NBR - 1;
				RET = RET + ft_putspace(NBR = NBR - ARGLEN);
			}
			if ((FNDFLAGS[3] == 1) && ((long int)ARG >= 0)) //(FNDFLAGS[2] != 1))// + et pas de -ARG || ((int)ARG > 0)))
			{
				if (env->putneg != 1)
				{
					//ft_putstr(">>DANS IF>>");
					RET = RET + ft_putchar('+');
					NBR = NBR - 1;
					//FNDFLAGS[3] == -1;
				}
			}
			if (NBR != -1 && NBR > ARGLEN)// && ITOK == 12)
			{

				if (FNDFLAGS[1] == 1 && FNDFLAGS[2] != 1) //0
				ft_putzero(env);
			}
		}
		if ((long int)ARG >= 0 && FNDFLAGS[3] == 1 && FNDFLAGS[2] == 1) // +
		{
			ARGLEN = ARGLEN + 1;
			RET = RET + ft_putchar('+');
		}
		ft_which_putnbrD(env);
		/*
		ft_putstr(">>RET2>>");
		ft_putnbr(NBR);
		ft_putstr("<<");
		*/
		if(FNDFLAGS[2] == 1 ) //-
		{

			if ( (FNDFLAGS[4] == 1 && NBR == -1)) // ' ' pas de NBR
			if ((int)ARG > 0)
			RET = RET + ft_putchar(' ');
			if (NBR != -1 && NBR > ARGLEN)// && ITOK == 12)
			{
				if (FNDFLAGS[2] == -1 && (FNDFLAGS[3] == 1) && ((long int)ARG > 0))//env->putneg != 1)//((int)ARG > 0)) // + et ARG >0
				NBR = NBR - 1;
				/*
				ft_putstr(">>NBR>>");
				ft_putnbr(NBR);
				ft_putstr("<<");*/
				//if (FNDFLAGS[3] == 1) // +
					//ARGLEN = ARGLEN + 1;
				if (FNDFLAGS[1] == 1 && FNDFLAGS[2] != 1) //0
					ft_putzero(env);
				else
					RET = RET + ft_putspace(NBR - ARGLEN);
			}
		}
	}
	return (1);
}
