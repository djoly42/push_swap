/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:14 by djoly             #+#    #+#             */
/*   Updated: 2016/03/24 23:39:32 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	init_2pile(t_2pile *pile)
{
	pile->v = 0;
	pile->c = 0;
	pile->w = 0;
	pile->error = 0;
	pile->print_all = 1;
	pile->ret_mv = 0;
	pile->pile_a.size = 0;
	pile->pile_b.size = 0;
}

void	init_pile_null(t_pile *pile)
{
	pile->beg = NULL;
	pile->last = NULL;
}

int		already_here(int data, t_node *test)
{
	int		i;
	t_node	*tmp;

	tmp = test;
	i = 0;
		if (data == tmp->data)
			return (1);
		if (tmp->prev == NULL)
			return (0);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				return (1);
			if (tmp->prev == NULL)
					return (0);
			tmp = tmp->prev;
		}
	return (1);
}

int		init_first(t_2pile *pile, int **tab, char **av, t_node *tmp)
{
	*tab[1] = 1;
	while ((*tab[2] = not_valid(pile, av[*tab[1]])) != 0)
	{
		if (*tab[2] == 1)
			return (1);
		else if (*tab[2] == 2)
			(*tab[1])++;
		if (*tab[0] == 0)
			return (1);
	}
	tmp->data = ft_atoi(av[*tab[1]]);
	pile->pile_a.min = tmp->data;
	pile->pile_a.max = tmp->data;
	pile->pile_a.size += 1;
	pile->pile_a.beg = tmp;
	tmp->prev = NULL;
	(*tab[1])++;
	return (0);
}

int    init_a(t_2pile *pile, char **av, int nb)
{
	int	i;
	int	a;
	t_node  *tmp;
	t_node  *tmp2;
	int *tab[3];

	tab[0] = &nb;
	tab[1] = &i;
	tab[2] = &a;
	tmp = (t_node*)malloc(sizeof(t_node));
	if (init_first(pile, tab, av, tmp))
		return (1);
	while (i <= nb)
	{
		if ((a = not_valid(pile, av[i])) == 1)
				return (1);
		if (a == 0)
		{
			if (already_here(ft_atoi(av[i]), tmp))
			{
				pile->error = 4;
				return (1);
			}
		tmp->next = (t_node*)malloc(sizeof(t_node));
		tmp->next->data = ft_atoi(av[i]);
		pile->pile_a.size += 1;
		if (tmp->next->data > pile->pile_a.max)
			pile->pile_a.max = tmp->next->data;
		if (tmp->next->data < pile->pile_a.min)
			pile->pile_a.min = tmp->next->data;
		tmp->next->prev = tmp;
		tmp2 = tmp->next;
		tmp = tmp->next;
		}
		i++;
	}
	if (pile->pile_a.size == 1)
	{
		tmp->next = NULL;
		pile->pile_a.last = tmp;
	}
	else
	{
		tmp2->next = NULL;
		pile->pile_a.last = tmp2;
	}
	return (0);
}

void	aff_pile(t_pile *pile)
{
	t_node	*tmp;

	tmp = pile->beg;
	if (tmp == NULL)
		return ;
	do
	{
		ft_printf("%d ",tmp->data);
		tmp = tmp->next;
	}while (tmp);
}

void	rev_aff_pile(t_pile *pile)
{
	t_node	*tmp;

	tmp = pile->last;
	if (tmp == NULL)
		return ;
	do
	{
		ft_printf("%d ",tmp->data);
		tmp = tmp->prev;
	}while (tmp);
}
