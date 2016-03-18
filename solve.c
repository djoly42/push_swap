/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/18 16:29:06 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		chr_forward(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	if (pile->beg == NULL)
		return (0);
	tmp = pile->beg;
	i = 0;
	if (tmp->next != NULL)
	{
		if (data > pile->max && (tmp->data == pile->max || pile->last->data == pile->max))
			return (0);
		if (data < pile->min && (tmp->data == pile->min || pile->last->data == pile->min))
			return (0);
		tmp = tmp->next;
		while (tmp)
		{
			i++;
			if (tmp->prev->data < data && data < tmp->data)
				break;
			if (tmp->next == NULL)
			{
				if (data > tmp->data)
					return (++i);
				i = -2;
				break;
			}
			tmp = tmp->next;
		}
	}
	return (i);
}

int		chr_back(int data, t_pile *pile)
{
	int	i;
	t_node	*tmp;

	if (pile->beg == NULL)
		return (0);
	tmp = pile->last;
	i = 0;
	if (tmp->prev != NULL)
	{
		if (data > pile->max && (tmp->data == pile->max || pile->beg->data == pile->max))
			return (0);
		if (data < pile->min && (tmp->data == pile->min || pile->beg->data == pile->min))
			return (0);
		tmp = tmp->prev;
		while (tmp)
		{
			i++;
			if (tmp->data < data && data < tmp->next->data)
				break;
			if (tmp->prev == NULL)
			{
				if (data < tmp->data)
					return (++i);
				i = -2;
				break;
			}
			tmp = tmp->prev;
		}
	}
	return (i);
}

int		which_behavior(int f[])
{
	int i;
	int ret;

	ret = f[0];
	i = 1;
	while(i < 4)
	{
		if(f[i] == -1)
			return (--ret);
		if (f[i] < ret)
			ret = i;
		i++;
	}
	return (ret);
}

int		find_path(t_pile *pile_a,t_pile *pile_b,int *f)
{
	f[0] = chr_forward(pile_a->beg->data, pile_b);
	f[1] = chr_back(pile_a->beg->data, pile_b);
	if (pile_a->beg->next != NULL)
	{
		f[2] = chr_forward(pile_a->beg->next->data, pile_b);
		f[3] = chr_back(pile_a->beg->next->data, pile_b);
	}
	return (0);
}

int		multi_r_pile(t_pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			ra(pile);
			n--;
		}
	}
	else
	{
		while (n)
		{
			rb(pile);
			n--;
		}
	}
	return (0);
}

int		multi_rr_pile(t_pile *pile, int n, char p)
{
	if (p == 'a')
	{
		while (n)
		{
			rra(pile);
			n--;
		}
	}
	else
	{
		while (n)
		{
			rrb(pile);
			n--;
		}
	}
	return (0);
}

void	init_f(int *f)
{
	f[0] = -1;
	f[1] = -1;
	f[2] = -1;
	f[3] = -1;
}



void	push0(t_pile *pile_a, t_pile *pile_b, int n)
{
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push1(t_pile *pile_a, t_pile *pile_b, int n)
{
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push2(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push3(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	behavior(t_pile *pile_a, t_pile *pile_b, int *f)
{
	int n;

	n = which_behavior(f);
	if (n == 0)
		push0(pile_a, pile_b, f[0]);
	else if (n == 1)
	push1(pile_a, pile_b, f[1]);
	else if (n == 2)
	push2(pile_a, pile_b, f[2]);
	else
	push3(pile_a, pile_b, f[3]);

}
int		solve(t_pile *pile_a, t_pile *pile_b)
{
	int	f[4];
	init_f(f);
	find_path(pile_a, pile_b, f);
//	ft_printf("f0:%d f1:%d f2:%d f3:%d ",f[0], f[1], f[2], f[3]);
//	push(pile_a, pile_b, which_behavior(f));
//	ft_printf("behaviour: %d \n", which_behavior(f));
	behavior(pile_a, pile_b, f);
//	rev_aff_pile(pile_a);
//	rev_aff_pile(pile_b);
	return (0);
}
