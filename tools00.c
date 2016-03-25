/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:17:34 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 14:18:39 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		rra(t_pile *pile_a)
{
	t_node	*tmp;

	tmp = pile_a->last;
	pile_a->last = pile_a->last->prev;
	pile_a->last->next = NULL;
	pile_a->beg->prev = tmp;
	tmp->next = pile_a->beg;
	pile_a->beg = tmp;
	pile_a->beg->prev = NULL;
	return (1);
}

int		rrb(t_pile *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->last;
	pile_b->last = pile_b->last->prev;
	pile_b->last->next = NULL;
	pile_b->beg->prev = tmp;
	tmp->next = pile_b->beg;
	pile_b->beg = tmp;
	pile_b->beg->prev = NULL;
	return (1);
}

void	rrr(t_pile *pile_a, t_pile *pile_b)
{
	rra(pile_a);
	rrb(pile_b);
}
