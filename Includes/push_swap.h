/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:57:48 by djoly             #+#    #+#             */
/*   Updated: 2016/03/18 18:13:34 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "ft_printf.h"
# include <stdlib.h>

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

void    pb(t_pile *pile_a, t_pile *pile_b);
void    pa(t_pile *pile_a, t_pile *pile_b);
void    rb(t_pile *pile_b);
void    ra(t_pile *pile_a);
void    rra(t_pile *pile_a);
void    rrb(t_pile *pile_b);
void    init_a(t_pile *pile_a, char **av, int nb);
void	init_pile_null(t_pile *pile);
void	aff_pile(t_pile *pile); //
void	rev_aff_pile(t_pile *pile); //
void	test(t_pile *pile_a, t_pile *pile_b);
void	rev_test(t_pile *pile_a, t_pile *pile_b);
int		solve(t_pile *pile_a, t_pile *pile_b);
int		multi_r_pile(t_pile *pile, int n, char p);
int		multi_rr_pile(t_pile *pile, int n, char p);
int		chrmax_forward(int data, t_pile *pile);
int		chrmin_forward(int data, t_pile *pile);
int		chrmax_back(int data, t_pile *pile);
int		chrmin_back(int data, t_pile *pile);

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
