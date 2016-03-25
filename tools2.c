/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:20:45 by djoly             #+#    #+#             */
/*   Updated: 2016/03/25 14:26:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

static int		check_bonus(t_2pile *pile, char *str)
{
	if (str[1] == 'v')
		pile->v = 1;
	else if (str[1] == 'c')
		pile->c = 1;
	else if (str[1] == 'w')
		pile->w = 1;
	else if (str[1] == 'n')
		pile->print_all = 0;
	else
	{
		pile->error = 2;
		return (1);
	}
	if (str[2] != '\0')
	{
		pile->error = 2;
		return (1);
	}
	return (2);
}

static int		check_nbr(t_2pile *pile, char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			pile->error = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int				not_valid(t_2pile *pile, char *str)
{
	int		i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
		return (check_nbr(pile, str));
	else if (str[i] == '-')
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			return (check_nbr(pile, str));
		return (check_bonus(pile, str));
	}
	else if (str[i] == '+')
		return (check_nbr(pile, str));
	pile->error = -1;
	return (1);
}
