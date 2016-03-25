/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:53:39 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 15:15:38 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		basic_test(t_2pile *pile)
{
	int		error;

	if ((error = nb_error(pile)) == 0)
		return (1);
	else if (error == 1 &&
			(pile->pile_a.beg->data > pile->pile_a.beg->next->data) &&
			(pile->pile_a.beg->data < pile->pile_a.last->data ||
			pile->pile_a.size == 2))
	{
		pile->ret_mv += sa(&pile->pile_a);
		print_last(pile, 3);
	}
	else if (error == 1 &&
			(pile->pile_a.last->data < pile->pile_a.last->prev->data))
		swap_last(pile);
	else if (error == (pile->pile_a.size - 1) && error == 2)
		reverse_pile3(pile);
	else if (error == (pile->pile_a.size - 1))
		reverse_pile(pile);
	else if (pile->pile_a.size < 6)
		solve2(pile);
	else
		return (0);
	return (1);
}

int		shrmin2(t_pile *pile)
{
	t_node	*tmp;
	int		min2;

	if (pile->beg == NULL)
		return (707);
	tmp = pile->beg;
	min2 = tmp->data;
	while (tmp)
	{
		if (tmp->data < min2)
			min2 = tmp->data;
		tmp = tmp->next;
	}
	return (min2);
}

int		solve3(t_2pile *pile)
{
	int		error;

	if ((error = nb_error(pile)) == 0)
		return (1);
	else if (error == 1 &&
			(pile->pile_a.beg->data > pile->pile_a.beg->next->data))
		pile->ret_mv += sa(&pile->pile_a);
	else if (pile->pile_a.size == 3 && error == 1 &&
			(pile->pile_a.last->data < pile->pile_a.last->prev->data))
		swap_last(pile);
	else if (error == (pile->pile_a.size - 1) && error == 2)
		reverse_pile3(pile);
	else
		return (0);
	return (1);
}

int		solve2(t_2pile *pile)
{
	int		tab[2];
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = pile->pile_a.beg;
	while (i < 3)
	{
		tab[0] = chrmin_forward(pile->pile_a.min, &pile->pile_a) - 1;
		tab[1] = chrmin_back(pile->pile_a.min, &pile->pile_a) + 1;
		if (tab[0] < (tab[1] + 1))
			multi_r_pile(pile, tab[0], 'a');
		else
			multi_rr_pile(pile, tab[1], 'a');
		pile->ret_mv += pb(&pile->pile_a, &pile->pile_b);
		print(pile, 2);
		pile->pile_a.size -= 1;
		pile->pile_a.min = shrmin2(&pile->pile_a);
		i++;
	}
	if (pile->pile_a.beg != NULL && solve3(pile) == 0)
		return (0);
	return (1);
}
