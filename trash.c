void	push2(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push3(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push4(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push5(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push6(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push7(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push8(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push9(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push10(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push11(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push12(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push13(t_pile *pile_a, t_pile *pile_b, int n)
{
	ra(pile_a);
	ra(pile_a);
	ra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void	push14(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_r_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

void		push15(t_pile *pile_a, t_pile *pile_b, int n)
{
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	rra(pile_a);
	if (n != 0)
		multi_rr_pile(pile_b, n, 'b');
	pb(pile_a, pile_b);
}

int    init_a(t_2pile *pile, char **av, int nb)
{
	int	i;
	int	a;
	t_node  *tmp;
	t_node  *tmp2;
	int *tab[3];

	tab[0] = &nb;
	tab[1] = &i;
	tab[2] = &a;
	if (init_first(pile, tab, av, tmp))
		return (1);
	/*i = 1;
	tmp = (t_node*)malloc(sizeof(t_node));
	while ((a = not_valid(pile, av[i])) != 0)
	{
		if (a == 1)
			return (1);
		else if (a == 2)
			i++;
		if (nb == 0)
			return (1);
	}
	tmp->data = ft_atoi(av[i]);
	pile->pile_a.min = tmp->data;
	pile->pile_a.max = tmp->data;
	pile->pile_a.size += 1;
	pile->pile_a.beg = tmp;
	tmp->prev = NULL;
	i++;
	*/
	while (i <= nb)
	{
		if ((a = not_valid(pile, av[i])) == 1)
				return (1);
		if (a == 0)
		{
			if (already_here(ft_atoi(av[i]), tmp))
			{
				pile->error = 4;
				return (1);
			}
		tmp->next = (t_node*)malloc(sizeof(t_node));
		tmp->next->data = ft_atoi(av[i]);
		pile->pile_a.size += 1;
		if (tmp->next->data > pile->pile_a.max)
			pile->pile_a.max = tmp->next->data;
		if (tmp->next->data < pile->pile_a.min)
			pile->pile_a.min = tmp->next->data;
		tmp->next->prev = tmp;
		tmp2 = tmp->next;
		tmp = tmp->next;
		}
		i++;
	}
	if (pile->pile_a.size == 1)
	{
		tmp->next = NULL;
		pile->pile_a.last = tmp;
	}
	else
	{
		tmp2->next = NULL;
		pile->pile_a.last = tmp2;
	}
	return (0);
}
