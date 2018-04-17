/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:59:10 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/04 16:59:11 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		main(int argc, char **argv)
{
	t_push	*push;

	push = (t_push*)malloc(sizeof(t_push));
	push->a = NULL;
	push->b = NULL;
	push->count = NULL;
	push->com = NULL;
	push->a = ft_read_args(argc, argv);
	ft_error_duplicates(push->a, push);
	ft_sort(push);
	ft_rewrite_commands(push);
	ft_putstr(push->com);
	ft_stek_del(push);
}
