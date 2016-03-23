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
