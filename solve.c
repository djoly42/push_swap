/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/22 13:16:05 by djoly            ###   ########.fr       */
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

	i = 11;
	while (i >= 0)
	{
		f[i] = -1;
		i--;
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
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push3(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	behavior(t_pile *pile_a, t_pile *pile_b, int *f)
{
	int		n;
//	int		i;
	n = which_behavior(f);
	if (n == 0)
		push0(pile_a, pile_b, f[0]);
	else if (n == 1)
	push1(pile_a, pile_b, f[1]);
	else if (n == 2)
	push2(pile_a, pile_b, f[2]);
	else
	push3(pile_a, pile_b, f[3]);

}
int		solve(t_pile *pile_a, t_pile *pile_b)
{
	int		f[12];
	int		i = 0;
	init_f(f);
	find_path(pile_a, pile_b, f);

	ft_printf("\n\npile_a:");
	rev_aff_pile(pile_a);
	ft_printf("\npile_b:");
	rev_aff_pile(pile_b);
	ft_putstr("\n");
	while (i < 12)
	{
		ft_printf("f[%d]:%d ", i, f[i]);
i++;
}
	ft_printf("\t\tbehaviour: %d \n", which_behavior(f));

	behavior(pile_a, pile_b, f);

	ft_printf("pile_a:");
	rev_aff_pile(pile_a);
	ft_printf("\npile_b:");
	rev_aff_pile(pile_b);

	return (0);
}
