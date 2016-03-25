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


void	behavior(t_2pile *pile, int *f)
{
	int		n;
	int		m;
	int		i;
	int		j;

	n = which_behavior(f);
	m = n;
	i = 0;
	j = 0;
	if (n == 0)
		push0(pile, f[0]);
	else if (n == 1)
		push1(pile, f[1]);
	else
	{
		while (m >= 0)
		{
			if (m == n)
				m = n - 2;
			if (m % 4 < 2)
			{
				pile->ret_mv += rra(&pile->pile_a);
				print(pile, 7);
			}
			else
			{
				pile->ret_mv += ra(&pile->pile_a);
				print(pile, 5);
			}
			m = m - 4;
		}
		if (n % 2 == 0)
			push0(pile, f[n]);
		else
			push1(pile, f[n]);
	}
}
int		solve2(t_2pile *pile)
{
	int		tab[2];
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = pile->pile_a.beg;
	while (i < 3)
	{
		tab[0] = chrmin_forward(pile->pile_a.min, &pile->pile_a) - 1;
		tab[1] = chrmin_back(pile->pile_a.min, &pile->pile_a) + 1;
		if (tab[0] < (tab[1] + 1))
			multi_r_pile(pile, tab[0], 'a');
		else
			multi_rr_pile(pile, tab[1], 'a');
		pile->ret_mv += pb(&pile->pile_a, &pile->pile_b);
		print(pile, 2);
		pile->pile_a.size -= 1;
		pile->pile_a.min = shrmin2(&pile->pile_a);
		i++;
	}
	if (pile->pile_a.beg != NULL && solve3(pile) == 0)
		return (0);
/*	tmp = pile->pile_b.beg;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		ft_printf(">>next=%d<<<", tmp->next);
		pile->ret_mv += pa(&pile->pile_a, &pile->pile_b);
		if(pile->pile_b.beg != NULL)
			print(pile, 1);
		else
			print_last(pile, 1);
		ft_printf(">>next=%d<<<", tmp->next);
//		if (tmp->next == NULL)
//			break;
	}*/
	return (1);
}
