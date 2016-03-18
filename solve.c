/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/18 11:11:56 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		chr_forward(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	tmp = pile->beg;
	i = 0;
	if (tmp->data > data && pile->last->data < data)
		return (0);
	if (tmp->next != NULL)
	{
		tmp = tmp->next;
		while (tmp)
		{
			i++;
			if (tmp->prev->data < data && data < tmp->data)
				break;
			if (tmp->next == NULL)
			{
				if (data > tmp->data)
					return (++i);
				i = -2;
				break;
			}
			tmp = tmp->next;
		}
	}
	return (i);
}

int		chr_back(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	tmp = pile->last;
	i = 0;
	if (tmp->data < data && pile->beg->data < data)
		return (1);
	if (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (tmp->data < data && data < tmp->next->data)
				break;
			if (tmp->prev == NULL)
			{
				if (data > tmp->data)
					return (++i);
				i = -2;
				break;
			}
			tmp = tmp->prev;
		}
	}
	return (i);
}

int		which_behavior(int f[])
{
	if (f[0] < f[1] && f[0] < f[2] && f[0] < f[3])
		return (0);
	if (f[0] > f[1] && f[1] < f[2] && f[1] < f[3])
		return (1);
	if (f[2] < f[1] && f[0] > f[2] && f[2] < f[3])
		return (2);
	if (f[3] < f[1] && f[3] < f[2] && f[0] > f[3])
		return (3);
	return (-1);
}

int		find_path(t_pile *pile_a,t_pile *pile_b,int *f)
{
	f[0] = chr_forward(pile_a->beg->data, pile_b);
	f[1] = chr_back(pile_a->beg->data, pile_b);
	if (pile_a->beg->next != NULL)
	{
		f[2] = chr_forward(pile_a->beg->next->data, pile_b);
		f[3] = chr_back(pile_a->beg->next->data, pile_b);
	}
	return (0);
}
/*
int		push(t_pile pile_a, t_pile pile_b, int *f)
{

	return (0);
}
*/
int		solve(t_pile *pile_a, t_pile *pile_b)
{
	int	f[4];
	f[0] = -1;
	f[1] = -1;
	f[2] = -1;
	f[3] = -1;
	find_path(pile_a, pile_b, f);
	ft_printf("f0:%d f1:%d f2:%d f3:%d",f[0], f[1], f[2], f[3]);
//	push(pile_a, pile_b, which_behavior(f[]));
	return (0);
}
