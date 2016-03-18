/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:14 by djoly             #+#    #+#             */
/*   Updated: 2016/03/18 16:49:04 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	init_pile_null(t_pile *pile)
{
	pile->beg = NULL;
	pile->last = NULL;
}

void    init_a(t_pile *pile_a, char **av, int nb)
{
	int i;
	t_node  *tmp;
	t_node  *tmp2;

	i = 2;
	tmp = (t_node*)malloc(sizeof(t_node));
	tmp->data = atoi(av[1]);
	pile_a->min = tmp->data;
	pile_a->max = tmp->data;
	tmp->index = 1;
	pile_a->beg = tmp;
	tmp->prev = NULL;
	while (i <= nb)
	{
		tmp->next = (t_node*)malloc(sizeof(t_node));
		tmp->next->data = atoi(av[i]);
		if (tmp->next->data > pile_a->max)
			pile_a->max = tmp->next->data;
		if (tmp->next->data < pile_a->min)
			pile_a->min = tmp->next->data;
		tmp->next->index = i;
		tmp->next->prev = tmp;
		tmp2 = tmp->next;
		tmp = tmp->next;
		i++;
	}
	tmp2->next = NULL;
	pile_a->last = tmp2;
}

void	aff_pile(t_pile *pile)
{
	//ft_printf("rev pile: ");
	t_node	*tmp;
	tmp = pile->beg;
	if (tmp == NULL)
		return ;
	do
	{
		ft_printf("%d ",tmp->data);
		tmp = tmp->next;
	}while (tmp);
//	ft_putchar('\n');
}

void	rev_aff_pile(t_pile *pile)
{
	//ft_printf("pile: ");
	t_node	*tmp;
	tmp = pile->last;
	if (tmp == NULL)
		return ;
	do
	{
		ft_printf("%d ",tmp->data);
		tmp = tmp->prev;
	}while (tmp);
	ft_printf("\t\tmax:%d min:%d", pile->max, pile->min);
	//ft_putchar('\n');
}
