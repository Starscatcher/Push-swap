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

typedef struct      s_count
{
  	int 		len;
    struct 	s_count   *next;
}                   t_count;

typedef struct      s_push
{
    t_stek  *a;
    t_stek  *b;
    t_count *count;
}                   t_push;

int 				ft_is_sort(char *arr);
t_count				*ft_make_count(void);
int 				ft_stek_sort(t_stek *stek);
int 				ft_new_med(int *med, int *secmed, t_push *push);
void				ft_push_b(t_push *push, int med);
t_stek*             ft_makelst(void);
int					ft_med(t_stek *stek, int num);
void                ft_rotate(t_push *push, char n);
void                ft_push(t_push *push, char n);
void                ft_pswap(t_push *push, char n);
void                ft_reverse_rotate(t_push *push, char n);


#endif
