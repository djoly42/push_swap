/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 12:11:58 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

static void	in_while(int n, int m, t_2pile *pile)
{
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
}

void		behavior(t_2pile *pile, int *f)
{
	int		n;
	int		m;
	int		i;
	int		j;

	n = which_behavior(f);
	m = n;
	i = 0;
	j = 0;
	if (n == 0)
		push0(pile, f[0]);
	else if (n == 1)
		push1(pile, f[1]);
	else
	{
		in_while(n, m, pile);
		if (n % 2 == 0)
			push0(pile, f[n]);
		else
			push1(pile, f[n]);
	}
}

void		init_f(int *f)
{
	int		i;

	i = 0;
	while (i < TAB)
	{
		f[i] = -1;
		i++;
	}
}

int			solve(t_2pile *pile)
{
	int		f[TAB];

	init_f(f);
	find_path(&pile->pile_a, &pile->pile_b, f);
	behavior(pile, f);
	return (0);
}
