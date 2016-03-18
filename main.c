/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:26 by djoly             #+#    #+#             */
/*   Updated: 2016/03/18 18:26:49 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Includes/push_swap.h"
/*
void    init_a(t_pile *pile_a, char *av, int nb)
{
	int i;
	t_node  *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	pile_a->size = nb;
	tmp->data = av[1];
	tmp->index = 0;
	tmp->prev = NULL;
	tmp->next = NULL;
	pile_a->beg = tmp;
	i = 2;
	while (i < nb)
	{
		tmp->next = (t_node*)malloc(sizeof(t_node));
		tmp->next->data = av[i];
		tmp->next->index = i;
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	pile_a->last = tmp;
}*/

int		chrmin_forward(int data, t_pile *pile)
{
	int	i;
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
				break;
			if (tmp->next == NULL)
					return (-1);
			tmp = tmp->next;
		}
	}
	return (i);
}


int		chrmax_forward(int data, t_pile *pile)
{
	int	i;
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
				break;
			if (tmp->next == NULL)
					return (-1);
			tmp = tmp->next;
		}
	}
	return (++i);
}

int		chrmin_back(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	if (pile->last == NULL)
		return (0);
	tmp = pile->last;
	i = 0;
	if (tmp->prev != NULL)
	{
		if (data == tmp->data)
			return (++i);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				break;
			if (tmp->prev == NULL)
					return (-1);
			tmp = tmp->prev;
		}
	}
	return (++i);
}

int		chrmax_back(int data, t_pile *pile)
{
	int	i;
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
				break;
			if (tmp->prev == NULL)
					return (-1);
			tmp = tmp->prev;
		}
	}
	return (i);
}

void	min_first(t_pile *pile_a, t_pile *pile_b)
{
//	t_node	*tmp;
	int		a;
	int		b;


	a = chrmax_forward(pile_b->max, pile_b);
	b = chrmax_back(pile_b->max, pile_b);
	ft_printf("\na:%d b:%d\n", a, b);
	if (a < b)
		multi_r_pile(pile_b, a, 'b');
	else
		multi_rr_pile(pile_b, b, 'b');
//	tmp = pile_b->beg;
	while (pile_b->beg)
		pa(pile_a, pile_b);
}
int     main(int argc, char **argv)
{
	t_pile  pile_a;
	t_pile  pile_b;

	if (argc == 1)
		return (0);
	init_a(&pile_a, argv, (argc - 1));
	init_pile_null(&pile_b);
//	pb(&pile_a, &pile_b);
//	pb(&pile_a, &pile_b);
//	pb(&pile_a, &pile_b);

	pile_a.size = 0;
	pile_b.size = 0;

	while (pile_a.beg != NULL)
		solve(&pile_a, &pile_b);
	//	rev_aff_pile(&pile_a);
		ft_printf("\navant min first:");
		rev_aff_pile(&pile_b);
		ft_printf("\n");
	min_first(&pile_a, &pile_b);
	ft_printf("nb =%d ", (pile_a.size + pile_b.size));
	ft_putstr("\npile a:");
	aff_pile(&pile_a);
/*	ft_putstr("\npile b:");
	rev_aff_pile(&pile_b);*/
//	ft_putstr("\npile a:");/
//	aff_pile(&pile_a);
//	ft_putstr("\npile b:");
//	aff_pile(&pile_b);
	//test(&pile_a, &pile_b);
	return (0);
}
