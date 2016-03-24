/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:23:24 by djoly             #+#    #+#             */
/*   Updated: 2016/03/24 23:12:28 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	print_pile(t_2pile *pile)
{
	if (pile->v == 1)
	{
		ft_putstr("\npile a:");
		rev_aff_pile(&pile->pile_a);
		ft_putstr("\npile b:");
		rev_aff_pile(&pile->pile_b);
		ft_putchar('\n');
	}
}

void	print_ret_mv(t_2pile *pile)
{
	if (pile->w)
		ft_printf("mv=%d\n", pile->ret_mv);
}

void	print(t_2pile *pile, int i)
{
	if (pile->print_all)
	{
		if (i == 1)
			ft_putstr("pa ");
		else if (i == 2)
			ft_putstr("pb ");
		else if (i == 3)
			ft_putstr("sa ");
		else if (i == 4)
			ft_putstr("sb ");
		else if (i == 5)
			ft_putstr("ra ");
		else if (i == 6)
			ft_putstr("rb ");
		else if (i == 7)
			ft_putstr("rra ");
		else if (i == 8)
			ft_putstr("rrb ");
	}
	print_pile(pile);
}

void	color(t_2pile *pile, int i)
{
	if (pile->print_all)
	{
		if (i == 1)
			ft_putstr("\033[36mpa\n\x1B[0m");
		else if (i == 2)
			ft_putstr("\033[35mpb\n\x1B[0m");
		else if (i == 3)
			ft_putstr("\033[36msa\n\x1B[0m");
		else if (i == 4)
			ft_putstr("\033[35msb\n\x1B[0m");
		else if (i == 5)
			ft_putstr("\033[36mra\n\x1B[0m");
		else if (i == 6)
			ft_putstr("\033[35mrb\n\x1B[0m");
		else if (i == 7)
			ft_putstr("\033[36mrra\n\x1B[0m");
		else if (i == 8)
			ft_putstr("\033[35mrrb\n\x1B[0m");
	}
}

void	print_last(t_2pile *pile, int i)
{
	if (pile->c == 1)
		color(pile, i);
	else if (pile->print_all)
	{
		if (i == 1)
			ft_putstr("pa\n");
		else if (i == 2)
			ft_putstr("pb\n");
		else if (i == 3)
			ft_putstr("sa\n");
		else if (i == 4)
			ft_putstr("sb\n");
		else if (i == 5)
			ft_putstr("ra\n");
		else if (i == 6)
			ft_putstr("rb\n");
		else if (i == 7)
			ft_putstr("rra\n");
		else if (i == 8)
			ft_putstr("rrb\n");
	}
	print_pile(pile);
}
