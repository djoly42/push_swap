/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:17:44 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 15:44:40 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static int	casse_pieds(int j, int i, int n)
{
	i += j > 0 && (i + n <= j) ? n : 0;
	i += j == 0 ? n : 0;
	return (i);
}


int		ft_wstrlen(const wchar_t *s, t_p *p)
{
	int	i;
	int	j;

	i = 0;
	j = p->after > 0 ? p->after : 0;
	while (*s)
	{
		if (*s <= 0x7F)
			i = casse_pieds(j, i, 1);
		else if (*s <= 0x7FF)
			i = casse_pieds(j, i, 2);
		else if (*s <= 0xFFFF)
			i = casse_pieds(j, i, 3);
		else if (*s <= 0x1FFFFF)
			i = casse_pieds(j, i, 4);
		(s)++;
	}
	return (i);
}
*/

int		ft_putwnstr(wchar_t *str, int n)
{
	int i;

	i = 0;
	while (*str != '\0' && (i + ft_wcharlen(*str)) <= n)
	{
		i += ft_put_w_char(*str);
		str++;
	}
	return (i);
}

int		ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i += ft_put_w_char(*str);
		str++;
	}
	return (i);
}

int		ft_wcharlen(wchar_t c)
{
	unsigned int e;

	e = (unsigned int)c;
	if (c >= 0 && c <= 255)
		return (1);
	else if (e > 255 && e < 0x10FFFF)
	{
		if (e < 0x07FF)
			return (2);
		else if (e < 0xFFFF)
			return (3);
		else
			return (4);
	}
	else
		return (1);
}

int		ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i += ft_wcharlen(*str);
		str++;
	}
	return (i);
}

int				ft_arglens(t_env *env)
{
	if (FNDFLAGS[6] == 1)
		return (ft_wstrlen((wchar_t)ARG));
	else
		return (ft_strlen((char *)ARG));
}
