/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:26 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 15:50:54 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	min_first(t_2pile *pile)
{
	int		a;
	int		b;

	a = chrmax_forward(pile->pile_b.max, &pile->pile_b);
	b = chrmax_back(pile->pile_b.max, &pile->pile_b);
	if (a < b)
		multi_r_pile(pile, a, 'b');
	else
		multi_rr_pile(pile, b, 'b');
	while (pile->pile_b.beg)
	{
		pile->ret_mv += pa(&pile->pile_a, &pile->pile_b);
		if (pile->pile_b.beg == NULL)
			print_last(pile, 1);
		else if (pile->pile_b.beg != NULL)
			print(pile, 1);
	}
}

int		main(int argc, char **argv)
{
	t_2pile	pile;

	init_2pile(&pile);
	if (argc == 1)
		return (0);
	if (init_a(&pile, argv, (argc - 1)))
	{
		ft_putstr("Error\n");
		return (0);
	}
	init_pile_null(&pile.pile_b);
	if (basic_test(&pile) == 0)
	{
		while (pile.pile_a.beg != NULL)
			solve(&pile);
	}
	min_first(&pile);
	print_ret_mv(&pile);
	return (0);
}
