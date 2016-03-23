/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/23 13:01:27 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		multi_r_pile(t_pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			ra(pile);
			n--;
		}
	}
	else
	{
		while (n)
		{
			rb(pile);
			n--;
		}
	}
	return (0);
}

int		multi_rr_pile(t_pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			rra(pile);
			n--;
		}
	}
	else
	{
		while (n)
		{
			rrb(pile);
			n--;
		}
	}
	return (0);
}

void	push0(t_pile *pile_a, t_pile *pile_b, int n)
{
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push1(t_pile *pile_a, t_pile *pile_b, int n)
{
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push2(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push3(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push4(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push5(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push6(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push7(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push8(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push9(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push10(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push11(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push12(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push13(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push14(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push15(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}


void	behavior(t_pile *pile_a, t_pile *pile_b, int *f)
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
		push0(pile_a, pile_b, f[0]);
	}
	else if (n == 1)
	{
//		ft_printf("\033[34m>>IF2<<\x1B[0m");
		push1(pile_a, pile_b, f[1]);
	}
	else
	{
//		ft_printf("\033[36m>>ELSE<<\x1B[0m");
	while (m >= 0)
	{
		if (m == n)
			m = n - 2;
		if (m % 4 < 2)
			rra(pile_a);
		else
			ra(pile_a);
		m = m - 4;
	}
	if (n % 2 == 0)
		push0(pile_a, pile_b, f[n]);
	else
		push1(pile_a, pile_b, f[n]);
	}


/*

	else if (n == 3)
		push3(pile_a, pile_b, f[3]);
	else if (n == 4)
		push4(pile_a, pile_b, f[4]);
	else if (n == 5)
		push5(pile_a, pile_b, f[5]);
	else if (n == 6)
		push6(pile_a, pile_b, f[6]);
	else if (n == 7)
		push7(pile_a, pile_b, f[7]);
	else if (n == 8)
		push8(pile_a, pile_b, f[8]);
	else if (n == 9)
		push9(pile_a, pile_b, f[9]);
	else if (n == 10)
		push10(pile_a, pile_b, f[10]);
	else if (n == 11)
		push11(pile_a, pile_b, f[11]);
		else if (n == 12)
		push12(pile_a, pile_b, f[12]);
	else if (n == 13)
		push13(pile_a, pile_b, f[13]);
	else if (n == 14)
		push14(pile_a, pile_b, f[14]);
	else if (n == 15)
		push15(pile_a, pile_b, f[15]);
*/
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


int		solve(t_pile *pile_a, t_pile *pile_b)
{
	 int		f[TAB];
//	int		i = 0;
	int a;
	init_f(f);
	find_path(pile_a, pile_b, f);
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
	behavior(pile_a, pile_b, f);


	if ((a = which_behavior(f)) > (TAB / 2))//!is_tri2(pile_b))
	{
		ft_printf("\033[95mTAB=%d \x1B[0m", TAB);
		ft_printf("\033[95mf[%d]\x1B[0m", a);
			ft_printf("\033[34m=%d \x1B[0m", f[a]);
		/*while (i < 40)
		{
			ft_printf("f[%d]:%d ", i, f[i]);
			i++;
		}


		ft_printf("\npile_a:");
		rev_aff_pile(pile_a);
		ft_printf("\npile_b:");
		rev_aff_pile(pile_b);*/
	}
	return (0);
}
