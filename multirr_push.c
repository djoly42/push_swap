/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multirr_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 12:08:25 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 15:49:02 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void		multi_r_pile(t_2pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			pile->ret_mv += ra(&pile->pile_a);
			print(pile, 5);
			n--;
		}
	}
	else
	{
		while (n)
		{
			pile->ret_mv += rb(&pile->pile_b);
			print(pile, 6);
			n--;
		}
	}
}

void		multi_rr_pile(t_2pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			pile->ret_mv += rra(&pile->pile_a);
			print(pile, 7);
			n--;
		}
	}
	else
	{
		while (n)
		{
			pile->ret_mv += rrb(&pile->pile_b);
			print(pile, 8);
			n--;
		}
	}
}

void		push0(t_2pile *pile, int n)
{
	if (n != 0)
		multi_r_pile(pile, n, 'b');
	pile->ret_mv += pb(&pile->pile_a, &pile->pile_b);
	print(pile, 2);
}

void		push1(t_2pile *pile, int n)
{
	if (n != 0)
		multi_rr_pile(pile, n, 'b');
	pile->ret_mv += pb(&pile->pile_a, &pile->pile_b);
	print(pile, 2);
}
