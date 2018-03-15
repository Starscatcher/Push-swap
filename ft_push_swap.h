#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct		s_stek
{
    int             num;
    struct s_stek  *prev;
    struct s_stek   *next;
}					t_stek;

typedef struct      s_push
{
    t_stek  *a;
    t_stek  *b;
}                   t_push;

t_stek*             ft_makelst(void);
void                ft_rotate(t_push *push, char n);
void                ft_push(t_push *push, char n);
void                ft_pswap(t_push *push, char n);
void                ft_reverse_rotate(t_push *push, char n);


#endif
