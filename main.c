/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:26 by djoly             #+#    #+#             */
/*   Updated: 2016/03/18 14:08:03 by djoly            ###   ########.fr       */
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



int     main(int argc, char **argv)
{
	t_pile  pile_a;
	t_pile  pile_b;

	if (argc == 1)
		return (0);
	init_a(&pile_a, argv, (argc - 1));
	init_pile_null(&pile_b);
	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	rev_aff_pile(&pile_a);
	rev_aff_pile(&pile_b);
	solve(&pile_a, &pile_b);

//	aff_pile(&pile_b);
	//test(&pile_a, &pile_b);
	return (0);
}
