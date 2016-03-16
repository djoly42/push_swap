/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/16 16:46:01 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"


int		pilechr(t_pile pile, int data)
{
	int	f;
	int	b;
	int find;
	t_node *tmp;
	t_node *tmp2;

	tmp = pile->beg;
	tmp2 = pile->last;
	f = 0;
	b = 0;
	find;
	while (!find)
	{
		if (data > tmp->data)// && data > tmp->next->data)
		{
			tmp = tmp->next;
			f++;
		}
		else
			break;
		if (data > tmp2->data && data > tmp->prev->data)
		{
			tmp = tmp->next;
			b++;
		}
		else
			break;



	}


}

int		solve(t_pile *pile_a, t_pile *pile_b)
{
	t_node	*tmp;
	int		a;

	while (pile_a->beg)
	{
		tmp = pile_a->beg
		a = pilechr(pile_b ,data);
	}
	return (0);
}
