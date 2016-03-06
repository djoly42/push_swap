
#include "push_swap.h"

void    init_a(t_pile *pile_a, char *av, int nb)
{
    int i;
    t_node  *tmp;
    tmp = (t_node*)malloc(sizeof(t_node));
    pile_a->size = nb;
    tmp->data = av[0];
    tmp->index = 0;
    tmp->prev = NULL;
    tmp->next = NULL;
    pile_a->beg = tmp;
    i = 1;
    while (i < nb)
    {
        tmp->next = (t_node*)malloc(sizeof(t_node));
        tmp->next->data = av[i];
        tmp->next->index = i;
        tmp->next->prev = tmp;
        tmp = tmp->next;
        i++;
    }
    pile_a->last = tmp;
}

int     main(int argc, char *argv)
{
    t_pile  pile_a;
    t_pile  pile_b;

    if (argc < 2)
        return (0);
    init_a(&pile_a, argv, (argc - 1));



    return (0);
}
