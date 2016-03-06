
#ifndef PUSH_SWAP
# define PUSH_SWAP

typedef struct  s_node t_node;
typedef struct  s_node
{
    t_node  *prev;
    t_node  *next;
    int     data;
    int     index;
}


typedef struct  s_pile t_pile;
typedef struct  s_pile
{
    t_node  *beg;
    t_node  *last;
    int     size;
}

typedef struct  s_env t_env;
typedef struct  s_env
{
    t_node  *b_beg;
    t_node  *b_last;
    int     b_size;
}

#endif
