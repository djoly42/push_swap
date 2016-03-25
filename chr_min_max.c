/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:24:17 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 11:26:09 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		chrmin_forward(int data, t_pile *pile)
{
	int		i;
	t_node	*tmp;

	if (pile->beg == NULL)
		return (0);
	tmp = pile->beg;
	i = 0;
	if (data == tmp->data)
		return (++i);
	if (tmp->next == NULL)
		return (-1);
	tmp = tmp->next;
	while (tmp)
	{
		i++;
		if (data == tmp->data)
			break ;
		if (tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
	}
	return (++i);
}

int		chrmin_back(int data, t_pile *pile)
{
	int		i;
	t_node	*tmp;

	if (pile->last == NULL)
		return (0);
	tmp = pile->last;
	i = 0;
	if (tmp->prev != NULL)
	{
		if (data == tmp->data)
			return (i);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				break ;
			if (tmp->prev == NULL)
				return (-1);
			tmp = tmp->prev;
		}
	}
	return (i);
}

int		chrmax_forward(int data, t_pile *pile)
{
	int		i;
	t_node	*tmp;

	if (pile->beg == NULL)
		return (0);
	tmp = pile->beg;
	i = 0;
	if (tmp->next != NULL)
	{
		if (data == tmp->data)
			return (i);
		tmp = tmp->next;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				break ;
			if (tmp->next == NULL)
				return (-1);
			tmp = tmp->next;
		}
	}
	return (i);
}

int		chrmax_back(int data, t_pile *pile)
{
	int		i;
	t_node	*tmp;

	if (pile->last == NULL)
		return (0);
	tmp = pile->last;
	i = 0;
	if (tmp->prev != NULL)
	{
		if (data == tmp->data)
			return (1);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				break ;
			if (tmp->prev == NULL)
				return (-1);
			tmp = tmp->prev;
		}
	}
	return (++i);
}
