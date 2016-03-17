
#include "ft_printf.h"

static void	ft_putzero(t_env *env)
{
	int i;

	i = -1;
	while (++i < (NBR - 1))
	 RET = RET + ft_putchar('0');

}

static void	ft_check_env(t_env *env)
{
	if (NBR != -1)// && ITOK == 12)
	{
		if (FNDFLAGS[1] == 1 && FNDFLAGS[2] == -1)
			ft_putzero(env);
		else
			RET = RET + ft_putspace(env->nbr - 1);
	}

}
int     fonct_C(t_env *env)
{
	if (FNDFLAGS[2] == 1)
	{
		//ft_check_env(env);
		//if (FNDFLAGS[6] == 1)
		RET = RET + ft_put_w_char((wchar_t)ARG);
		//else
		//RET = RET + ft_putchar((char)ARG);
		ft_check_env(env);
	}
	else
	{
		ft_check_env(env);
		//if (FNDFLAGS[6] == 1)
		RET = RET + ft_put_w_char((wchar_t)ARG);
		//else
		//RET = RET + ft_putchar((char)ARG);
	}
    return(1);
}
