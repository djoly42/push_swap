
#include "Includes/push_swap.h"

void    sa(t_pile *pile)
{
    int tmp;
    int i;

    tmp = pile->beg->data;
    i  = pile->beg->index;
    pile->beg->data = pile->beg->next->data;
    pile->beg->index = pile->beg->next->index;
    pile->beg->next->data = tmp;
    pile->beg->next->index = i;
}

void    sb(t_pile *pile)
{
    int tmp;
    int i;

    tmp = pile->beg->data;
    i  = pile->beg->index;
    pile->beg->data = pile->beg->next->data;
    pile->beg->index = pile->beg->next->index;
    pile->beg->next->data = tmp;
    pile->beg->next->index = i;

}

void    ss(t_pile *pile_a, t_pile *pile_b)
{
    sa(pile_a);
    sb(pile_b);
}

void    pb(t_pile *pile_a, t_pile *pile_b)
{
	t_node  *tmp;

	if (pile_a->beg == NULL)
		return ;
	tmp = pile_a->beg;
	if (pile_a->beg->next != NULL)
	{
		pile_a->beg = pile_a->beg->next;
		pile_a->beg->prev = NULL;
	}
	else
		init_pile_null(pile_a);
	if (pile_b->beg != NULL)
	{
		tmp->next = pile_b->beg;
		pile_b->beg= tmp;
		pile_b->beg->next->prev = pile_b->beg;
		pile_b->beg->prev = NULL;
	}
	else
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		pile_b->beg = tmp;
		pile_b->last = tmp;
	}
	if (tmp->data > pile_b->max)
		pile_b->max = tmp->data;
	if (tmp->data < pile_b->min)
		pile_b->min = tmp->data;
}

void    pa(t_pile *pile_a, t_pile *pile_b)
{
	t_node  *tmp;
	//ft_putstr("STR");
	if (pile_b->beg == NULL)
	{
		//ft_putstr("RETURN");
		return ;
	}
	tmp = pile_b->beg;
	if (pile_b->beg->next != NULL)
	{
		pile_b->beg = pile_b->beg->next;
		pile_b->beg->prev = NULL;
	}
	else
		init_pile_null(pile_b);
	if (pile_a->beg != NULL)
	{
		//ft_putstr(">>IF");
		tmp->next = pile_a->beg;
		pile_a->beg= tmp;
		pile_a->beg->next->prev = pile_a->beg;
		pile_a->beg->prev = NULL;
	}
	else
	{
		//ft_putstr(">>ELSE");
		tmp->next = NULL;
		tmp->prev = NULL;
		pile_a->beg = tmp;
		pile_a->last = tmp;
	}
	if (tmp->data > pile_a->max)
		pile_a->max = tmp->data;
	if (tmp->data < pile_a->min)
		pile_a->min = tmp->data;
}

/*
void    pa(t_pile *pile_a, t_pile *pile_b)
{
    t_node  *tmp;
//	ft_putstr("STR");
    tmp = pile_b->beg;
	if (pile_b->beg != pile_b->last)
	{
	pile_b->beg = pile_b->beg->next;
	pile_b->beg->prev = pile_b->last;
	pile_b->last->next = pile_b->beg;
	}
	else
	{
		pile_b->beg = NULL;
		pile_b->last = NULL;
	}
	if (pile_a->beg != NULL)
	{
		ft_putstr(">>IF");
		pile_a->beg->prev = tmp;
    	tmp->next = pile_a->beg;
    	pile_a->beg = tmp;
		pile_a->beg->prev = pile_a->beg->prev = pile_a->last;
		pile_a->last->next = pile_a->beg;
	}
	else
	{
		ft_putstr(">>ELSE");
		tmp->next = tmp;
		tmp->prev = tmp;
		pile_a->beg = tmp;
		pile_a->last = tmp;
	}

}
*/
void    ra(t_pile *pile_a)
{
    t_node  *tmp;
    tmp = pile_a->beg;
    pile_a->beg = pile_a->beg->next;
    pile_a->beg->prev = NULL;
    pile_a->last->next = tmp;
    pile_a->last = tmp;
}

void    rb(t_pile *pile_b)
{
    t_node  *tmp;
    tmp = pile_b->beg;
    pile_b->beg = pile_b->beg->next;
    pile_b->beg->prev = NULL;
    pile_b->last->next = tmp;
    pile_b->last = tmp;
}

void    rr(t_pile *pile_a, t_pile *pile_b)
{
    ra(pile_a);
    rb(pile_b);
}

void    rra(t_pile *pile_a)
{
    t_node  *tmp;
    tmp = pile_a->last;
    pile_a->beg = pile_a->beg->next;
    pile_a->beg->prev = NULL;
    pile_a->last->next = tmp;
    pile_a->last = tmp;
}

void    rrb(t_pile *pile_b)
{
    t_node  *tmp;
    tmp = pile_b->last;
    pile_b->beg = pile_b->beg->next;
    pile_b->beg->prev = NULL;
    pile_b->last->next = tmp;
    pile_b->last = tmp;
}

void    rrr(t_pile *pile_a, t_pile *pile_b)
{
    rra(pile_a);
    rrb(pile_b);
}
