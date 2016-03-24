/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:53:39 by djoly             #+#    #+#             */
/*   Updated: 2016/03/23 21:06:36 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		basic_test(t_2pile *pile)
{
	t_node	*tmp;
	int		error;

	error = 0;
	tmp = pile->pile_a.beg->next;
	while (tmp)
	{
		if (tmp->data < tmp->prev->data)
			error++;
		tmp = tmp->next;
	}
	return (error);
}

int		reverse_pile1(t_2pile *pile)
{
	int a;



	return (1);
}

int		reverse_pile3(t_2pile *pile)
{
	pile->ret_mv += sa(&pile->pile_a);
	pile->ret_mv += rra(&pile->pile_a);

	return (1);
}

int		solve2(t_2pile *pile)
{
	int		a;

	if ((a = basic_test(pile)) == 0)
	{
		ft_printf("\033[35m>>>BASIC 1 TEST %d<<<\n\x1B[0m", a);
		return (1);
	}
	else if (a == (pile->pile_a.size - 1) && a == 2)
	{
		reverse_pile3(pile);
	}
	if (pile->pile_a.beg->data > pile->pile_a.beg->next->data)
	{
		pile->ret_mv += sa(&pile->pile_a);
	}
	if ((a = basic_test(pile)) == 0)
	{
		ft_printf("\033[35m>>>BASIC 3 TEST %d<<<\n\x1B[0m", a);
		return (1);
	}
	ft_printf("\033[35m>>>BASIC 4 TEST %d<<<\n\x1B[0m", a);


	return (1);
}
