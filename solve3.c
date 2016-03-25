/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:42:19 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 13:34:59 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		reverse_pile3(t_2pile *pile)
{
	pile->ret_mv += sa(&pile->pile_a);
	print(pile, 3);
	pile->ret_mv += rra(&pile->pile_a);
	print_last(pile, 7);
	return (1);
}

int		nb_error(t_2pile *pile)
{
	t_node	*tmp;
	int		error;

	error = 0;
	tmp = pile->pile_a.beg->next;
	while (tmp)
	{
		if (tmp->data < tmp->prev->data)
			error++;
		tmp = tmp->next;
	}
	return (error);
}

int		swap_last(t_2pile *pile)
{
	if (pile->pile_a.last->data > pile->pile_a.last->prev->prev->data)
	{
		pile->ret_mv += rra(&pile->pile_a);
		print(pile, 7);
		pile->ret_mv += rra(&pile->pile_a);
		print(pile, 7);
		pile->ret_mv += sa(&pile->pile_a);
		print(pile, 3);
		pile->ret_mv += ra(&pile->pile_a);
		print(pile, 5);
		pile->ret_mv += ra(&pile->pile_a);
		print_last(pile, 5);
	}
	else
		solve2(pile);
	return (1);
}

int		reverse_pile(t_2pile *pile)
{
	while (pile->pile_a.beg)
	{
		pile->ret_mv += pb(&pile->pile_a, &pile->pile_b);
		print(pile, 2);
	}
	while (pile->pile_b.beg)
	{
		if (pile->pile_b.beg->data != pile->pile_b.last->data)
		{
			pile->ret_mv += rrb(&pile->pile_b);
			print(pile, 8);
		}
		pile->ret_mv += pa(&pile->pile_a, &pile->pile_b);
		if (pile->pile_b.beg != NULL)
			print(pile, 1);
		else
			print_last(pile, 1);
	}
	return (1);
}
