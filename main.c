/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:26:26 by djoly             #+#    #+#             */
/*   Updated: 2016/03/24 22:11:10 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Includes/push_swap.h"


int		chrmin_forward(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	if (pile->beg == NULL)
		return (0);
	tmp = pile->beg;
	i = 0;
//	if (tmp->next != NULL)
//	{
		if (data == tmp->data)
			return (++i);
		if (tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
		while (tmp)
		{
		//	ft_putstr("pile a:");
			i++;
			if (data == tmp->data)
				break;
			if (tmp->next == NULL)
					return (-1);
			tmp = tmp->next;
		}
	//}
	return (++i);
}




int		chrmin_back(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	if (pile->last == NULL)
		return (0);
	tmp = pile->last;
	i = 0;
	if (tmp->prev != NULL)
	{
		if (data == tmp->data)
			return (i);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				break;
			if (tmp->prev == NULL)
					return (-1);
			tmp = tmp->prev;
		}
	}
	return (i);
}

int		chrmax_forward(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	if (pile->beg == NULL)
		return (0);
	tmp = pile->beg;
	i = 0;
	if (tmp->next != NULL)
	{
		if (data == tmp->data)
			return (i);
		tmp = tmp->next;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				break;
			if (tmp->next == NULL)
					return (-1);
			tmp = tmp->next;
		}
	}
	return (i);
}

int		chrmax_back(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	if (pile->last == NULL)
		return (0);
	tmp = pile->last;
	i = 0;
	if (tmp->prev != NULL)
	{
		if (data == tmp->data)
			return (1);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (data == tmp->data)
				break;
			if (tmp->prev == NULL)
					return (-1);
			tmp = tmp->prev;
		}
	}
	return (++i);
}

void	min_first(t_2pile *pile)
{
	int		a;
	int		b;

	a = chrmax_forward(pile->pile_b.max, &pile->pile_b);
	b = chrmax_back(pile->pile_b.max, &pile->pile_b);
	if (a < b)
		multi_r_pile(pile, a, 'b');
	else
		multi_rr_pile(pile, b, 'b');
	while (pile->pile_b.beg)
	{
		pile->ret_mv += pa(&pile->pile_a, &pile->pile_b);
		if (pile->print_all && pile->pile_b.beg == NULL)
			print_last(pile, 1);
		else if (pile->print_all && pile->pile_b.beg != NULL)
			print(pile, 1);
	}
}

int	is_tri(t_pile *pile)
{
	t_node	*tmp;

	tmp = pile->beg->next;
	while (tmp)
	{
		if (tmp->data < tmp->prev->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_tri2(t_pile *pile)
{
	t_node	*tmp;

	tmp = pile->beg->next;
	while (tmp)
	{
		if (tmp->data > tmp->prev->data)
		{
			if (tmp->data != pile->max)
				return (0);
		}
		tmp = tmp->next;
	}
//ft_printf("\033[35m>>>Pile triee<<<\n\x1B[0m");
	return (1);
}

int     main(int argc, char **argv)
{
	t_2pile	pile;
	init_2pile(&pile);
	if (argc == 1) // un parametre -bonus ?
		return (0);
	if (init_a(&pile, argv, (argc - 1)))// un parametre -bonus ?
	{
		ft_putstr("Error\n");
		return (0);
	}
	init_pile_null(&pile.pile_b);
	if (basic_test(&pile) == 0)
	{
			while (pile.pile_a.beg != NULL)
				solve(&pile);
	}
	min_first(&pile);
	print_ret_mv(&pile);
	//ft_printf("v=%d c=%d")
	is_tri(&pile.pile_a);
	/*ft_putstr("\npile a:");
	rev_aff_pile(&pile.pile_a);
	ft_putstr("\npile b:");
	rev_aff_pile(&pile.pile_b);
	ft_putchar('\n');*/
	return (0);
}
