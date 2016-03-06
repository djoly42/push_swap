
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

