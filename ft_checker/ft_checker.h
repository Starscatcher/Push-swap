/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:20:06 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:20:07 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../ft_push_swap/ft_push_swap.h"

typedef struct		s_option
{
  int n;
  int c;
  int v;
  int h;
  int l;
  int k;
}					t_option;

t_option		*ft_create_option(t_option *option);
char			**ft_find_option(int *argc, char **argv, t_option *option);
void			ft_push_print(t_option *option, char *str, t_push *push);
void			ft_print_elem(t_stek *stek, int on);
void			ft_commands_in_colour(t_option *o, char *str, t_push *push);
void			ft_make_commands(char *str, t_push *push, t_option *option);
void			ft_op_help(t_option *option, t_push *push);
int				ft_p(t_push *pus, char n);
int				ft_s(t_push *pus, char n, int x);
int				ft_r(t_push *pus, char n, int x);
int				ft_rr(t_push *pus, char n, int x);

#endif
