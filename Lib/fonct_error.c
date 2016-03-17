/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 13:54:24 by djoly             #+#    #+#             */
/*   Updated: 2016/03/03 10:15:32 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fonct_error(t_env *env)
{
	//ft_putstr("error");
	if (FNDFLAGS[2] == -1 && NBR != -1)
	{
		if (FNDFLAGS[1] == 1)
		RET = RET + ft_putzero2(NBR - 1);
		else
		RET = RET + ft_putspace(NBR - 1);
	}
	RET = RET + ft_putchar(FORMAT[IFOR]);
	if (FNDFLAGS[2] == 1 && NBR != -1)
		RET = RET + ft_putspace(NBR - 1);
//ft_putstr(">>");
}
