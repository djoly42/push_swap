/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:34:23 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 13:42:29 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	test(t_pile *pile_a, t_pile *pile_b)
{
	rrb(pile_b);
	rra(pile_a);
	rev_aff_pile(pile_a);
	rev_aff_pile(pile_b);
	aff_pile(pile_a);
	aff_pile(pile_b);
	ft_printf("rr\n");
	rrb(pile_b);
	//rra(pile_a);
	rev_aff_pile(pile_a);
	rev_aff_pile(pile_b);
	aff_pile(pile_a);
	aff_pile(pile_b);
	/*ft_putstr("\t\t\tpilea ");
	aff_pile(pile_a);
	ft_putstr("\n");

	ft_putstr("pb: ");
	pb(pile_a, pile_b);
	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pb: ");
	pb(pile_a, pile_b);
	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pb: ");
	pb(pile_a, pile_b);
	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);

	ft_putstr("\trevpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\trevpilea ");
	rev_aff_pile(pile_a);

	ft_putstr("\n");

	ft_putstr("pa: ");
	pa(pile_a, pile_b);
	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pa: ");
	pa(pile_a, pile_b);
	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pa: ");
	pa(pile_a, pile_b);
	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);

	ft_putstr("\trevpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\trevpilea ");
	rev_aff_pile(pile_a);
}

void	rev_test(t_pile *pile_a, t_pile *pile_b)
{

	ft_putstr("\t\t\tpilea ");
	rev_aff_pile(pile_a);
	ft_putstr("\n");

	ft_putstr("pb: ");
	pb(pile_a, pile_b);
	ft_putstr("\tpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\tpilea ");
	rev_aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pb: ");
	pb(pile_a, pile_b);
	ft_putstr("\tpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\tpilea ");
	rev_aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pb: ");
	pb(pile_a, pile_b);
	ft_putstr("\tpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\tpilea ");
	rev_aff_pile(pile_a);

	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);

	ft_putstr("\n");

	ft_putstr("pa: ");
	pa(pile_a, pile_b);
	ft_putstr("\tpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\tpilea ");
	rev_aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pa: ");
	pa(pile_a, pile_b);
	ft_putstr("\tpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\tpilea ");
	rev_aff_pile(pile_a);
	ft_putchar('\n');

	ft_putstr("pa: ");
	pa(pile_a, pile_b);
	ft_putstr("\tpileb ");
	rev_aff_pile(pile_b);
	ft_putstr("\tpilea ");
	rev_aff_pile(pile_a);

	ft_putstr("\tpileb ");
	aff_pile(pile_b);
	ft_putstr("\tpilea ");
	aff_pile(pile_a);*/
}
