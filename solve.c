/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/22 17:07:40 by djoly            ###   ########.fr       */
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

void	init_f(int *f)
{
	int		i;

	i = 0;
	while (i < 12)
	{
		*f = -1;
		i++;
		f++;
	}
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

void	behavior(t_pile *pile_a, t_pile *pile_b, int *f)
{
	int		n;
	int		m;
//	int		i;

//	int		i;
	n = which_behavior(f);
	m = n;
	if (n == 0)
		push0(pile_a, pile_b, f[0]);
	else if (n == 1)
		push1(pile_a, pile_b, f[1]);
	else if (n == 2)
		push2(pile_a, pile_b, f[2]);
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
}
int		solve(t_pile *pile_a, t_pile *pile_b)
{
	int		f[12];
	int		i = 0;
	init_f(f);
	find_path(pile_a, pile_b, f);
/*
	ft_printf("\n\npile_a:");
	rev_aff_pile(pile_a);
	ft_printf("\npile_b:");
	rev_aff_pile(pile_b);
	*/
	ft_putstr("");
	while (i < 12)
	{
		printf("f[%d]:%d ", i, f[i]);
i++;
}
couleur("34");
	printf(" >>%d<<", which_behavior(f));
	couleur("0");

	behavior(pile_a, pile_b, f);
/*
	ft_printf("pile_a:");
	rev_aff_pile(pile_a);
	ft_printf("\npile_b:");
	rev_aff_pile(pile_b);
*/
	return (0);
}
