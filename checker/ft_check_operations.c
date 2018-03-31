/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:19:55 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:19:56 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_p(t_push *push, char n)
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
}

void	ft_s(t_push *push, char n, int x)
{
	if (n == 'a' && push->a && push->a->next)
	{
		x = push->a->num;
		push->a->num = push->a->next->num;
		push->a->next->num = x;
	}
	else if (n == 'b' && push->b && push->b->next)
	{
		x = push->b->num;
		push->b->num = push->b->next->num;
		push->b->next->num = x;
	}
}

void	ft_r(t_push *push, char n, int x)
{
	if (n == 'a' && push->a && push->a->next)
	{
		x = push->a->num;
		while (push->a->next)
		{
			push->a->num = push->a->next->num;
			push->a = push->a->next;
		}
		push->a->num = x;
		while (push->a->prev)
			push->a = push->a->prev;
	}
	else if (n == 'b' && push->b && push->b->next)
	{
		x = push->b->num;
		while (push->b->next)
		{
			push->b->num = push->b->next->num;
			push->b = push->b->next;
		}
		push->b->num = x;
		while (push->b->prev)
			push->b = push->b->prev;
	}
}

void	ft_rr(t_push *push, char n, int x)
{
	if (n == 'a' && push->a && push->a->next)
	{
		while (push->a->next)
			push->a = push->a->next;
		x = push->a->num;
		while (push->a->prev)
		{
			push->a->num = push->a->prev->num;
			push->a = push->a->prev;
		}
		push->a->num = x;
	}
	else if (n == 'b' && push->b && push->b->next)
	{
		while (push->b->next)
			push->b = push->b->next;
		x = push->b->num;
		while (push->b->prev)
		{
			push->b->num = push->b->prev->num;
			push->b = push->b->prev;
		}
		push->b->num = x;
	}
}
