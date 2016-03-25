/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:43:16 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 14:17:04 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

t_node	*node_beg(t_node *node, t_node *prev)
{
	t_node	*tmp;

	tmp = node;
	tmp->prev = prev;
	return (tmp);
}

t_node	*node_beg2(t_node *tmp, t_node *beg1)
{
	tmp->next = beg1;
	beg1 = tmp;
	beg1->next->prev = beg1;
	beg1->prev = NULL;
	return (beg1);
}

int		pb(t_pile *pile_a, t_pile *pile_b)
{
	t_node		*tmp;

	if (pile_a->beg == NULL)
		return (0);
	tmp = pile_a->beg;
	if (pile_a->beg->next != NULL)
		pile_a->beg = node_beg(pile_a->beg->next, NULL);
	else
		init_pile_null(pile_a);
	if (pile_b->beg != NULL)
		pile_b->beg = node_beg2(tmp, pile_b->beg);
	else
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		pile_b->beg = tmp;
		pile_b->last = tmp;
		pile_b->max = tmp->data;
		pile_b->min = tmp->data;
	}
	if (tmp->data > pile_b->max)
		pile_b->max = tmp->data;
	if (tmp->data < pile_b->min)
		pile_b->min = tmp->data;
	return (1);
}

int		pa(t_pile *pile_a, t_pile *pile_b)
{
	t_node		*tmp;

	if (pile_b->beg == NULL)
		return (0);
	tmp = pile_b->beg;
	if (pile_b->beg->next != NULL)
		pile_b->beg = node_beg(pile_b->beg->next, NULL);
	else
		init_pile_null(pile_b);
	if (pile_a->beg != NULL)
		pile_a->beg = node_beg2(tmp, pile_a->beg);
	else
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		pile_a->beg = tmp;
		pile_a->last = tmp;
	}
	if (tmp->data > pile_a->max)
		pile_a->max = tmp->data;
	if (tmp->data < pile_a->min)
		pile_a->min = tmp->data;
	return (1);
}

int		ra(t_pile *pile_a)
{
	t_node	*tmp;

	tmp = pile_a->beg;
	pile_a->beg = pile_a->beg->next;
	pile_a->beg->prev = NULL;
	pile_a->last->next = tmp;
	tmp->prev = pile_a->last;
	pile_a->last = tmp;
	pile_a->last->next = NULL;
	return (1);
}
