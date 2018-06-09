/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:40:39 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/12 16:40:39 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_push		*ft_create_push(t_push *push)
{
	push = (t_push*)malloc(sizeof(t_push));
	push->a = NULL;
	push->b = NULL;
	push->count = NULL;
	push->com = NULL;
	return (push);
}

int			ft_read_and_print(t_option *option, char *str, t_push *push, int c)
{
	if (option->v)
	{
		ft_printf("\n{sea wave}Start{eoc}\n\n");
		ft_push_print(option, str, push);
		ft_printf("\n");
	}
	while (get_next_line(0, &str))
	{
		ft_make_commands(str, push, 0);
		option && option->v ? ft_push_print(option, str, push) : 0;
		ft_strdel(&str);
		c++;
	}
	if (option->v)
	{
		ft_printf("{sea wave}Final{eoc}\n\n");
		ft_push_print(option, str, push);
	}
	return (c);
}

void		ft_is_correct(t_push *push)
{
	if (ft_check_sort_lst(push->a) && !push->b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int			main(int argc, char **argv)
{
	char		*str;
	t_push		*push;
	int			len;
	int			commands;
	t_option	*option;

	str = NULL;
	push = NULL;
	option = NULL;
	push = ft_create_push(push);
	option = ft_create_option(option);
	argv = ft_find_option(&argc, argv, option);
	if (option->h)
		ft_op_help(option, push);
	push->a = ft_read_args(argc, argv);
	len = ft_stek_len(push->a);
	ft_error_duplicates(push->a, push);
	commands = ft_read_and_print(option, str, push, 0);
	if (option->l)
		ft_printf("Length of stack is {sea wave}%d{eoc}.\n\n", len);
	if (option->n)
		ft_printf("Number of commands is {sea wave}%d{eoc}.\n\n", commands);
	ft_is_correct(push);
	free(option);
}
