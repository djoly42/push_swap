
#include <push_swap.h>

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
    tmp = pile_a->beg;
    pile_a->beg = pile_a->beg->next;
    tmp->next = pile_b->beg;
    pile_b->beg = tmp;
}

void    pa(t_pile *pile_a, t_pile *pile_b)
{
    t_node  *tmp;
    tmp = pile_b->beg;
    pile_b->beg = pile_b->beg->next;
    tmp->next = pile_a->beg;
    pile_a->beg = tmp;
}

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
