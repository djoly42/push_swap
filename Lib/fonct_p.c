/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:35:37 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 15:51:41 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:36:04 by djoly             #+#    #+#             */
/*   Updated: 2016/02/26 17:36:26 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int hexa_leni(unsigned int nb)
{
	int i;

	if (nb == 0)
	return (1);
	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

static int hexa_lenl(unsigned long int nb)
{
	int i;

	if (nb == 0)
	return (1);
	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

static int hexa_lenll(unsigned long long int nb)
{
	int i;

	if (nb == 0)
	return (1);
	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

static int hexa_lenj(uintmax_t nb)
{
	int i;

	if (nb == 0)
	return (1);
	i = 0;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

static int hexa_len(t_env *env)
{
	return (hexa_lenll((unsigned long long int)ARG));
}

static void print_hexai(unsigned int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexai(nb / 16, env);
		ft_putchar(HEXA[nb % 16]);
	}
}

static void print_hexal(unsigned long int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexal(nb / 16, env);
		ft_putchar(HEXA[nb % 16]);
	}
}

static void print_hexall(long long unsigned int nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexall(nb / 16, env);
		ft_putchar(HEXA[nb % 16]);

	}
}

static void print_hexaj(uintmax_t nb, t_env *env)
{
	if (nb != 0)
	{
		print_hexall(nb / 16, env);
		ft_putchar(HEXA[nb % 16]);
	}
}

static int print_hexa(t_env *env)
{
	print_hexal((long long unsigned int)ARG, env);
	/*
	if (FNDFLAGS[6] == 1)
	print_hexal((long long unsigned int)ARG, env);
	else if (FNDFLAGS[6] == 2)
	print_hexall((long long unsigned int)ARG, env);
	else if (FNDFLAGS[7] == 1)
	print_hexaj((uintmax_t)ARG, env);
	else
	print_hexai((unsigned int)ARG, env);
	*/
}


static int 	print_dies(t_env *env)
{
	ft_putzero2(1);
	if (ITOK == 10)
	ft_putchar('X');
	else
	ft_putchar('x');
	return (2);
}



static int ft_test0(t_env *env)
{
	if (FNDFLAGS[6] == 1 && (long long unsigned int)ARG == 0)
		return (1);
	else if (FNDFLAGS[6] == 2 && (long long unsigned int)ARG == 0)
		return (1);
	else if (FNDFLAGS[7] == 1 && (uintmax_t)ARG == 0)
		return (1);
	else if (FNDFLAGS[6] == -1 && FNDFLAGS[7] == -1 && (unsigned int)ARG == 0)
		return (1);
	else
		return (0);
}

static void x_prec(t_env *env)
{
	if (NBRPREC != -1)
	{
		if (FNDFLAGS[2] == -1 && NBR != -1 && NBR > NBRPREC)
		{
			/*
			ft_putstr(">>nbr>>");
			ft_putnbr(RET);
			ft_putstr("<<");
			*/
			if (NBRPREC > ARGLEN )
				RET = RET + ft_putspace(NBR - NBRPREC - 2);
			else if (ft_test0 (env))
				RET = RET + ft_putspace(NBR);
			else
			{
				RET = RET + ft_putspace(NBR - ARGLEN);
			}
		}
		/*ft_putstr(">>nbr>>");
		ft_putnbr(RET);
		ft_putstr("<<");*/
		//if (FNDFLAGS[0] == 1 && !ft_test0(env))//#
		//	RET = RET + print_dies(env);
		RET = RET + print_dies(env);
		/*ft_putstr(">>nbr>>");
		ft_putnbr(RET);
		ft_putstr("<<");*/
		if (NBRPREC != -1 && NBRPREC > (ARGLEN - 2) )//.
			RET = RET + ft_putzero2(NBRPREC - ARGLEN + 2);
			/*ft_putstr(">>nbr>>");
			ft_putnbr(RET);
			ft_putstr("<<");*/
		if (ft_test0(env))
		{
			//ft_putstr(">>");
			if (NBRPREC != -1)// NBR != -1
				RET = RET + ft_putchar('0');
			//	ft_putstr("<<");
		}
		else
		{
			print_hexa(env);
			RET = RET + ARGLEN - 2;
			/*ft_putstr(">>nbr>>");
			ft_putnbr(RET);
			ft_putstr("<<");*/
		}

		// ft_putnbr(RET);
		if (FNDFLAGS[2] == 1 && NBRPREC != -1 && NBR > NBRPREC)// NBR != -1
		RET = RET + ft_putspace(NBR - NBRPREC);
	}
	else
		RET = RET + print_dies(env);
		/*ft_putstr(">>nbr>>");
		ft_putnbr(RET);
		ft_putstr("<<");*/
}

int                     fonct_p(t_env *env)
{
	ARGLEN = hexa_len(env);
	ARGLEN = ARGLEN + 2;
	//ft_putnbr(env->arglen);

	if (FNDFLAGS[9] == 1)
	x_prec(env);
	else
	{
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == -1 && NBR > ARGLEN) // pas de - et nbr pas de 0
			RET = RET + ft_putspace(NBR - env->arglen);
		RET = RET + print_dies(env);
		if (FNDFLAGS[2] == -1 && FNDFLAGS[1] == 1 && NBR > ARGLEN)
			RET = RET + ft_putzero2(NBR - ARGLEN);

		if (ft_test0(env))
		RET = RET + ft_putchar('0');
		else
		{
		print_hexa(env);
		RET = RET + ARGLEN - 2;
		}
		// ft_putnbr(RET);
		if (FNDFLAGS[2] == 1 && NBR != -1 && NBR > env->arglen && FNDFLAGS[9] == -1) // - et nbr
		{
			//if (FNDFLAGS[0] == 1)
			//    NBR = NBR - 2;
			RET = RET + ft_putspace(NBR - ARGLEN);
		}
	}
	//ft_putnbr(RET);
	return (1);
}
