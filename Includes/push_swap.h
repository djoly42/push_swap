/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:57:48 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 13:42:21 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "ft_printf.h"
# include <stdlib.h>
#define TAB 200

typedef struct  s_node t_node;
struct  s_node
{
    t_node  *prev;
    t_node  *next;
    int     data;
	int     index;
};

typedef struct  s_pile t_pile;
struct  s_pile
{
	t_node	*beg;
	t_node	*last;
	int		size;
	int		min;
	int		max;
};

typedef struct  s_2pile t_2pile;
struct  s_2pile
{
	int		v;
	int		c;
	int		w;
	int		error;
	int		print_all;
	int		ret_mv;
	t_pile	pile_a;
	t_pile	pile_b;
};

int		pa(t_pile *pile_a, t_pile *pile_b);
int		pb(t_pile *pile_a, t_pile *pile_b);
int		sa(t_pile *pile);
int		sb(t_pile *pile);
int		ra(t_pile *pile_a);
int		rb(t_pile *pile_b);
int		rra(t_pile *pile_a);
int		rrb(t_pile *pile_b);
void	aff_pile(t_pile *pile); //
int		basic_test(t_2pile *pile);
int		chrmax_forward(int data, t_pile *pile);
int		chrmin_forward(int data, t_pile *pile);
int		chrmax_back(int data, t_pile *pile);
int		chrmin_back(int data, t_pile *pile);
int		find_path(t_pile *pile_a,t_pile *pile_b,int *f);
int	    init_a(t_2pile *pile, char **av, int nb);
void	init_pile_null(t_pile *pile);
void	init_2pile(t_2pile *pile);
int 	is_tri(t_pile *pile);
int		is_tri2(t_pile *pile);
void	multi_r_pile(t_2pile *pile, int n, char p);
void	multi_rr_pile(t_2pile *pile, int n, char p);
int		nb_error(t_2pile *pile);
int		not_valid(t_2pile *pile, char *str);
void	print(t_2pile *pile, int i);
void	print_last(t_2pile *pile, int i);
void	print_ret_mv(t_2pile *pile);
void	push0(t_2pile *pile, int n);
void	push1(t_2pile *pile, int n);
int		reverse_pile(t_2pile *pile);
void	rev_test(t_pile *pile_a, t_pile *pile_b);
void	rev_aff_pile(t_pile *pile); //
int		reverse_pile3(t_2pile *pile);
int		reverse_pile(t_2pile *pile);
int		shrmin2(t_pile *pile);
int		solve(t_2pile *pile);
int		solve2(t_2pile *pile);
int		solve3(t_2pile *pile);
int		swap_last(t_2pile *pile);
//void	test(t_pile *pile_a, t_pile *pile_b);
int		which_behavior(int f[]);


/*
typedef struct  s_env t_env;
struct  s_env
{
    t_node  *b_beg;
    t_node  *b_last;
    int     b_size;
};
*/
#endif
