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
# include "../libft/libft.h"
# include "../push_swap/ft_push_swap.h"

void				ft_p(t_push *pus, char n);
void				ft_s(t_push *pus, char n, int x);
void				ft_r(t_push *pus, char n, int x);
void				ft_rr(t_push *pus, char n, int x);

#endif
