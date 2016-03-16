/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:14 by djoly             #+#    #+#             */
/*   Updated: 2016/03/16 15:55:12 by djoly            ###   ########.fr       */
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
	tmp->index = 1;
	pile_a->beg = tmp;
	tmp->prev = NULL;
	while (i <= nb)
	{
		//write(1,"ok", 2);
		tmp->next = (t_node*)malloc(sizeof(t_node));
		tmp->next->data = atoi(av[i]);
		//ft_printf("s:%s ", av[i]);
		//ft_printf("d:%d ", tmp->data);
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
	t_node	*tmp;
//write(1,"11", 2);
	tmp = pile->beg;
	if (tmp == NULL)
		return ;
	do
	{
//		write(1,"22", 2);
		ft_printf("%d ",tmp->data);
		tmp = tmp->next;
	}while (tmp);
}

void	rev_aff_pile(t_pile *pile)
{
	t_node	*tmp;
//write(1,"11", 2);
	tmp = pile->last;
	if (tmp == NULL)
		return ;
	do
	{
//		write(1,"22", 2);
		ft_printf("%d ",tmp->data);
		tmp = tmp->prev;
	}while (tmp);
}
