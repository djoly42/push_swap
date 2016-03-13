
#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "../p4_home/ft_printf.h"
# include <stdlib.h>

typedef struct  s_node t_node;
struct  s_node
{
    t_node  *prev;
    t_node  *next;
    int     data;
int     index;
};


typedef struct  s_pile t_pile;
struct  s_pile
{
    t_node  *beg;
    t_node  *last;
    int     size;
};
/*
typedef struct  s_env t_env;
struct  s_env
{
    t_node  *b_beg;
    t_node  *b_last;
    int     b_size;
};
*/
#endif
