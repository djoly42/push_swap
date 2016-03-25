/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:53:13 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 11:14:53 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	aff_pile(t_pile *pile)
{
	t_node	*tmp;

	tmp = pile->beg;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
}

void	rev_aff_pile(t_pile *pile)
{
	t_node	*tmp;

	tmp = pile->last;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->prev;
	}
}

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
