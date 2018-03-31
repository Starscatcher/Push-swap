/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_and_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:21:28 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 17:21:28 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rotate_b(t_push *push, int c)
{
	c = push->b->num;
	while (push->b->next)
	{
		push->b->num = push->b->next->num;
		push->b = push->b->next;
	}
	push->b->num = c;
	while (push->b->prev)
		push->b = push->b->prev;
}

void	ft_rotate(t_push *push, char n)
{
	int c;

	c = 0;
	if (n == 'a' && push->a && push->a->next)
	{
		c = push->a->num;
		while (push->a->next)
		{
			push->a->num = push->a->next->num;
			push->a = push->a->next;
		}
		push->a->num = c;
		while (push->a->prev)
			push->a = push->a->prev;
	}
	else if (n == 'b' && push->b && push->b->next)
		ft_rotate_b(push, c);
	ft_print_commands(push, "r", n, 3);
}

void	ft_reverse_b(t_push *push, int c)
{
	while (push->b->next)
		push->b = push->b->next;
	c = push->b->num;
	while (push->b->prev)
	{
		push->b->num = push->b->prev->num;
		push->b = push->b->prev;
	}
	push->b->num = c;
}

void	ft_reverse_rotate(t_push *push, char n)
{
	int c;

	c = 0;
	if (n == 'a' && push->a && push->a->next)
	{
		while (push->a->next)
			push->a = push->a->next;
		c = push->a->num;
		while (push->a->prev)
		{
			push->a->num = push->a->prev->num;
			push->a = push->a->prev;
		}
		push->a->num = c;
		if (push->count->rb)
		{
			push->count->rb--;
			ft_reverse_rotate(push, 'b');
		}
	}
	else if (n == 'b' && push->b && push->b->next)
		ft_reverse_b(push, c);
	ft_print_commands(push, "rr", n, 4);
}
