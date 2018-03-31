/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:51:58 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:51:59 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stek	*ft_del_first(t_stek *stek)
{
	if (stek->next)
	{
		stek = stek->next;
		free(stek->prev);
		stek->prev = NULL;
		return (stek);
	}
	else
	{
		free(stek);
		return (NULL);
	}
}

void	ft_push(t_push *push, char n)
{
	if (n == 'a' && push->b)
	{
		if (push->a)
		{
			push->a->prev = ft_makelst();
			push->a->prev->next = push->a;
			push->a = push->a->prev;
		}
		push->a = !push->a ? ft_makelst() : push->a;
		push->a->num = push->b->num;
		push->b = ft_del_first(push->b);
	}
	else if (n == 'b' && push->a)
	{
		if (push->b)
		{
			push->b->prev = ft_makelst();
			push->b->prev->next = push->b;
			push->b = push->b->prev;
		}
		push->b = !push->b ? ft_makelst() : push->b;
		push->b->num = push->a->num;
		push->a = ft_del_first(push->a);
	}
	ft_print_commands(push, "p", n, 3);
}

void	ft_pswap(t_push *push, char n)
{
	int r;

	if (n == 'a' && push->a->next)
	{
		r = push->a->num;
		push->a->num = push->a->next->num;
		push->a->next->num = r;
		if (push->b && push->b->next && push->b->num < push->b->next->num)
			ft_pswap(push, 'b');
	}
	else if (n == 'b' && push->b->next)
	{
		r = push->b->num;
		push->b->num = push->b->next->num;
		push->b->next->num = r;
	}
	ft_print_commands(push, "s", n, 3);
}
