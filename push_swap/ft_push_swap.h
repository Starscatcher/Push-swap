#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_stek
{
    int             num;
    struct s_stek  *prev;
    struct s_stek   *next;
}					t_stek;

typedef struct      s_count
{
  	int 	len;
    int 	rb;
    struct 	s_count   *next;
}                   t_count;

typedef struct      s_push
{
    t_stek  *a;
    t_stek  *b;
    t_count *count;
  	char 	*command;
  	int 	fin;
}                   t_push;


void				ft_rewrite_commands(t_push *push);
int 				ft_less_than_mad(t_stek *stek, int med);
int 				ft_more_then_med(t_stek *stek, int med);
void				ft_del_first_stek(t_push *push);
void				ft_new_count(t_push *push);
int 				ft_sort(t_push *push);
int 				ft_check_sort_arr(int *arr, int size);
t_count				*ft_make_count(void);
int 				ft_check_sort_lst(t_stek *stek);
int 				ft_new_med(int *med, t_push *push);
void				ft_push_b(t_push *push, int med);
t_stek*             ft_makelst(void);
int					ft_med(t_stek *stek, int num, int where);
void                ft_rotate(t_push *push, char n);
void                ft_push(t_push *push, char n);
void                ft_pswap(t_push *push, char n);
void                ft_reverse_rotate(t_push *push, char n);
void				ft_sort_up_three(t_push *push);
void				ft_sort_three(t_push *push);


#endif
