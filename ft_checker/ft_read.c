/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:20:17 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:20:18 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_make_commands(char *str, t_push *push)
{
	ft_strequ(str, "sa") ? ft_s(push, 'a', 0) : 0;
	ft_strequ(str, "sb") ? ft_s(push, 'b', 0) : 0;
	ft_strequ(str, "pa") ? ft_p(push, 'a') : 0;
	ft_strequ(str, "pb") ? ft_p(push, 'b') : 0;
	ft_strequ(str, "ra") ? ft_r(push, 'a', 0) : 0;
	ft_strequ(str, "rb") ? ft_r(push, 'b', 0) : 0;
	ft_strequ(str, "rra") ? ft_rr(push, 'a', 0) : 0;
	ft_strequ(str, "rrb") ? ft_rr(push, 'b', 0) : 0;
	if (ft_strequ(str, "rr"))
	{
		ft_r(push, 'a', 0);
		ft_r(push, 'b', 0);
	}
	else if (ft_strequ(str, "rrr"))
	{
		ft_rr(push, 'a', 0);
		ft_rr(push, 'b', 0);
	}
	else if (ft_strequ(str, "ss"))
	{
		ft_s(push, 'a', 0);
		ft_s(push, 'b', 0);
	}
}
/*
int		main(int argc, char **argv)
{
	char	*str;
	t_push	*push;

	push = (t_push*)malloc(sizeof(t_push));
	push->a = ft_read_args(argc, argv);
	push->b = NULL;
	while (get_next_line(0, &str))
		ft_make_commands(str, push);
	ft_check_sort_lst(push->a) ? ft_putstr("OK\n") : ft_putstr("KO\n");
}*/
