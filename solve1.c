/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 10:59:24 by djoly             #+#    #+#             */
/*   Updated: 2016/03/22 17:15:20 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		chr_forward(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;
	if (pile->beg == NULL)
		return (0);
	if (pile->beg == pile->last)
		return (0);
	if (data > pile->max)
		return (chrmax_forward(pile->max, pile));
	if (data < pile->min)
		return (chrmin_forward(pile->min, pile));
	tmp = pile->beg;
	if (data > tmp->data && data < pile->last->data)
		return (0);
	i = 0;
	if (tmp->next != NULL)
	{
		tmp = tmp->next;
		while (tmp)
		{
			i++;
			if (tmp->prev->data > data && data > tmp->data)
				break;
			if (tmp->prev->data == pile->max && data > tmp->data)
				break;
			if (tmp->next == NULL)
			{
				couleur("31");
				printf("     >>LOVE<<        ");
				couleur("0");
				if (data < tmp->data)
					return (i);
				i = -1;
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

	if (pile->beg == NULL)
		return (0);
	if (data > pile->max)
		return (chrmax_back(pile->max, pile));
	if (data < pile->min)
		return (chrmin_back(pile->min, pile));

	tmp = pile->last;
//	tmp = pile->beg;
	if (data > pile->beg->data && data < pile->last->data)
		return (0);
	i = 1;
	if (tmp->prev != NULL)
	{
		if (data > pile->max && (tmp->data == pile->max))// || pile->beg->data == pile->max))
			return (1);
		if (data < pile->min && (tmp->data == pile->min))// || pile->beg->data == pile->min))
			return (1);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (tmp->data > data && data > tmp->next->data)
				break;
			if (tmp->prev == NULL)
			{
				couleur("31");
				printf("      >>HATE<<         ");
				couleur("0");
				if (data > tmp->data)
					return (--i);
				i = -1;
				break;
			}
			tmp = tmp->prev;
		}
	}
	return (--i);
}

int		which_behavior(int f[])
{
	int		i;
	int		ret;
	int		j;

	ret = 0;
	i = 1;
	j = 0;
	while(i < 16)
	{

		if(f[i] == -1)
			return (ret);
		if (i % 2 == 1)
		{
			j++;
			if ((f[i] + j) < f[ret])
				ret = i;
		}
		else
		{
			if ((f[i] + j) < f[ret])
				ret = i;
		}
		i++;
	}
	return (ret);
}

int		find_path(t_pile *pile_a,t_pile *pile_b,int *f)
{
	int		i;
	int 	j;
	t_node	*tmp;
	t_node	*tmp2;

	tmp = pile_a->beg;
	tmp2 = pile_a->last;
	i = 4;
	j = 1;
	f[0] = chr_forward(pile_a->beg->data, pile_b);
	f[1] = chr_back(pile_a->beg->data, pile_b);
	f[2] = chr_forward(pile_a->last->data, pile_b);
	f[3] = chr_back(pile_a->last->data, pile_b);
	while (i < 16)
	{
		if (tmp->next)
		{
			f[i] = chr_forward(tmp->next->data, pile_b);
			f[i + 1] = chr_back(tmp->next->data, pile_b);
			tmp = tmp->next;
		}
		if (tmp2->prev)
		{
			f[i + 2] = chr_forward(tmp2->prev->data, pile_b);
			f[i + 3] = chr_back(tmp2->prev->data, pile_b);
			tmp2 = tmp2->prev;
		}
		i = i + 4;
		j++;
	}
	return (0);
}
