/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:14:59 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 14:19:01 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		sa(t_pile *pile)
{
	int tmp;
	int i;

	tmp = pile->beg->data;
	i = pile->beg->index;
	pile->beg->data = pile->beg->next->data;
	pile->beg->index = pile->beg->next->index;
	pile->beg->next->data = tmp;
	pile->beg->next->index = i;
	return (1);
}

int		sb(t_pile *pile)
{
	int tmp;
	int i;

	tmp = pile->beg->data;
	i = pile->beg->index;
	pile->beg->data = pile->beg->next->data;
	pile->beg->index = pile->beg->next->index;
	pile->beg->next->data = tmp;
	pile->beg->next->index = i;
	return (1);
}

void	ss(t_pile *pile_a, t_pile *pile_b)
{
	sa(pile_a);
	sb(pile_b);
}

int		rb(t_pile *pile_b)
{
	t_node	*tmp;

	tmp = pile_b->beg;
	pile_b->beg = pile_b->beg->next;
	pile_b->beg->prev = NULL;
	pile_b->last->next = tmp;
	tmp->prev = pile_b->last;
	pile_b->last = tmp;
	pile_b->last->next = NULL;
	return (1);
}

void	rr(t_pile *pile_a, t_pile *pile_b)
{
	ra(pile_a);
	rb(pile_b);
}
