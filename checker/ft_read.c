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
	int x;

	x = 0;
	ft_strequ(str, "sa") ? ft_s(push, 'a', x) : 0;
	ft_strequ(str, "sb") ? ft_s(push, 'b', x) : 0;
	ft_strequ(str, "pa") ? ft_p(push, 'a') : 0;
	ft_strequ(str, "pb") ? ft_p(push, 'b') : 0;
	ft_strequ(str, "ra") ? ft_r(push, 'a', x) : 0;
	ft_strequ(str, "rb") ? ft_r(push, 'b', x) : 0;
	ft_strequ(str, "rra") ? ft_rr(push, 'a', x) : 0;
	ft_strequ(str, "rrb") ? ft_rr(push, 'b', x) : 0;
	if (ft_strequ(str, "rr"))
	{
		ft_r(push, 'a', x);
		ft_r(push, 'b', x);
	}
	else if (ft_strequ(str, "rrr"))
	{
		ft_rr(push, 'a', x);
		ft_rr(push, 'b', x);
	}
	else if (ft_strequ(str, "ss"))
	{
		ft_s(push, 'a', x);
		ft_s(push, 'b', x);
	}
}
/*
int		main(int argc, char **argv)
{
	char	*str;
	t_push	*push;
	int		fd;

	push = (t_push*)malloc(sizeof(t_push));
	push->a = ft_read_args(argc, argv);
	push->b = NULL;
	fd = open("../1", O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ft_make_commands(str, push);
	}
	ft_check_sort_lst(push->a) ? printf("OK") : printf("KO");
}*/
