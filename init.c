/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:14 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 11:14:56 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

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

int		init_first(t_2pile *pile, int *tab, char **av, t_node *tmp)
{
	tab[1] = 1;
	while ((tab[2] = not_valid(pile, av[tab[1]])) != 0)
	{
		if (tab[2] == 1)
			return (1);
		else if (tab[2] == 2)
			tab[1]++;
		if (tab[0] == 0)
			return (1);
	}
	tmp->data = ft_atoi(av[tab[1]]);
	pile->pile_a.min = tmp->data;
	pile->pile_a.max = tmp->data;
	pile->pile_a.size += 1;
	pile->pile_a.beg = tmp;
	tmp->prev = NULL;
	tab[1]++;
	return (0);
}

int		in_while(t_2pile *pile, int *tab, char **av, t_node **tmp3)
{
	if ((tab[2] = not_valid(pile, av[tab[1]])) == 1)
		return (1);
	if (tab[2] == 0)
	{
		if (already_here(ft_atoi(av[tab[1]]), tmp3[0]))
		{
			pile->error = 4;
			return (1);
		}
		tmp3[0]->next = (t_node*)malloc(sizeof(t_node));
		tmp3[0]->next->data = ft_atoi(av[tab[1]]);
		pile->pile_a.size += 1;
		if (tmp3[0]->next->data > pile->pile_a.max)
			pile->pile_a.max = tmp3[0]->next->data;
		if (tmp3[0]->next->data < pile->pile_a.min)
			pile->pile_a.min = tmp3[0]->next->data;
		tmp3[0]->next->prev = tmp3[0];
		tmp3[1] = tmp3[0]->next;
		tmp3[0] = tmp3[0]->next;
	}
	tab[1]++;
	return (0);
}

int		init_a(t_2pile *pile, char **av, int nb)
{
	int		tab[3];
	t_node	*tmp3[2];

	tab[0] = nb;
	tmp3[0] = (t_node*)malloc(sizeof(t_node));
	if (init_first(pile, tab, av, tmp3[0]))
		return (1);
	while (tab[1] <= tab[0])
	{
		if (in_while(pile, tab, av, tmp3) == 1)
			return (1);
	}
	if (pile->pile_a.size == 1)
	{
		tmp3[0]->next = NULL;
		pile->pile_a.last = tmp3[0];
	}
	else
	{
		tmp3[1]->next = NULL;
		pile->pile_a.last = tmp3[1];
	}
	return (0);
}
