/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/24 21:11:11 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void		multi_r_pile(t_2pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			pile->ret_mv += ra(&pile->pile_a);
			print(pile, 5);
			n--;
		}
	}
	else
	{
		while (n)
		{
			pile->ret_mv += rb(&pile->pile_b);
			print(pile, 6);
			n--;
		}
	}
}

void		multi_rr_pile(t_2pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			pile->ret_mv += rra(&pile->pile_a);
			print(pile, 7);
			n--;
		}
	}
	else
	{
		while (n)
		{
			pile->ret_mv += rrb(&pile->pile_b);
			print(pile, 8);
			n--;
		}
	}
}

void		push0(t_2pile *pile, int n)
{
	if (n != 0)
		multi_r_pile(pile, n, 'b');
	pile->ret_mv += pb(&pile->pile_a, &pile->pile_b);
	print(pile, 2);
}

void		push1(t_2pile *pile, int n)
{
	if (n != 0)
		multi_rr_pile(pile, n, 'b');
	pile->ret_mv += pb(&pile->pile_a, &pile->pile_b);
	print(pile, 2);
}

void	behavior(t_2pile *pile, int *f)
{
	int		n;
	int		m;
	int		i;
	int		j;
//	int		i;
	n = which_behavior(f);
	m = n;
	i = 0;
	j = 0;
	if (n == 0){
//	ft_printf("\033[35m>>IF1<<\x1B[0m");
		push0(pile, f[0]);
	}
	else if (n == 1)
	{
//		ft_printf("\033[34m>>IF2<<\x1B[0m");
		push1(pile, f[1]);
	}
	else
	{
//		ft_printf("\033[36m>>ELSE<<\x1B[0m");
	while (m >= 0)
	{
		if (m == n)
			m = n - 2;
		if (m % 4 < 2)
		{
			pile->ret_mv += rra(&pile->pile_a);
			print(pile, 7);
		}
		else
		{
			pile->ret_mv += ra(&pile->pile_a);
			print(pile, 5);
		}
		m = m - 4;
	}
	if (n % 2 == 0)
		push0(pile, f[n]);
	else
		push1(pile, f[n]);
	}
}


void	init_f(int *f)
{
	int		i;

	i = 0;
	while (i < TAB)
	{
		f[i] = -1;
		i++;
	}
}


int		solve(t_2pile *pile)
{
	 int		f[TAB];
//	int		i = 0;
	//int a;
	init_f(f);
	find_path(&pile->pile_a, &pile->pile_b, f);
/*
	ft_printf("\n\npile_a:");
	rev_aff_pile(pile_a);
	ft_printf("\npile_b:");
	rev_aff_pile(pile_b);

	ft_putstr("\n");

*/
//ft_putstr("pb \x1B");
//	couleur("34");

//	couleur("0");
	behavior(pile, f);


//	if ((a = which_behavior(f)) > (TAB / 2))//!is_tri2(pile_b))
//	{
///		ft_printf("\033[95mTAB=%d \x1B[0m", TAB);
	//	ft_printf("\033[95mf[%d]\x1B[0m", a);
	//		ft_printf("\033[34m=%d \x1B[0m", f[a]);
		/*while (i < 40)
		{
			ft_printf("f[%d]:%d ", i, f[i]);
			i++;
		}


		ft_printf("\npile_a:");
		rev_aff_pile(pile_a);
		ft_printf("\npile_b:");
		rev_aff_pile(pile_b);*/
	//}
	return (0);
}
