
#include "push_swap.h"

/*
void    init_a(t_pile *pile_a, char *av, int nb)
{
	int i;
	t_node  *tmp;
	tmp = (t_node*)malloc(sizeof(t_node));
	pile_a->size = nb;
	tmp->data = av[1];
	tmp->index = 0;
	tmp->prev = NULL;
	tmp->next = NULL;
	pile_a->beg = tmp;
	i = 2;
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
}*/

void    init_a(t_pile *pile_a, char *av, int nb)
{
	int i;
	t_node  *tmp;
	t_node  *tmp2;

	i = 1;
	while (i < nb)
	{
		tmp = (t_node*)malloc(sizeof(t_node));
		tmp->data = ft_atoi(av[i]);
		tmp->index = i;
		if (i == 1)
		{
			pile_a->beg = tmp;
			tmp->prev = NULL;
		}
		else
			tmp->prev = tmp2;
		tmp2 = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp = NULL;
	pile_a->last = tmp2;
}

void	aff_pile(t_pile pile)
{
	t_node	*tmp;

	tmp = pile->beg;
	while (tmp)
	{
		ft_printf("%d ",tmp->data);
		tmp = tmp->next;
	}
}

int     main(int argc, char *argv)
{
	t_pile  pile_a;
	t_pile  pile_b;

	if (argc < 2)
		return (0);
	init_a(&pile_a, argv, (argc - 1));
	aff_pile(pile_a);	


	return (0);
}
