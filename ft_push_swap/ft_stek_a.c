/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stek_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:30:51 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 16:30:52 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_while_less_than_mad(t_push *push, int med, int pa)
{
	while (!ft_less_than_mad(push->b, med))
	{
		if (push->b->num >= med)
		{
			ft_push(push, 'a');
			pa++;
			push->count->len--;
		}
		else
		{
			ft_rotate(push, 'b');
			push->count->rb++;
		}
	}
	return (pa);
}

void	ft_if_rb(t_push *push)
{
	if (push->count && push->count->rb)
	{
		while (push->count->rb > 0)
		{
			ft_reverse_rotate(push, 'b');
			push->count->rb--;
		}
	}
}

int		ft_while_more_than_mad(t_push *push, int *med, int *pa, int *pb)
{
	int ra;

	ra = 0;
	while (!ft_more_then_med(push->a, *med))
	{
		if (push->a->num >= *med)
		{
			ft_rotate(push, 'a');
			ra++;
		}
		else
		{
			ft_push(push, 'b');
			++*pb;
			--*pa;
		}
	}
	return (ra);
}

int		ft_while_ra(t_push *push, int ra)
{
	while (ra > 0)
	{
		ft_reverse_rotate(push, 'a');
		ra--;
	}
	return (ra);
}

void	ft_push_a(t_push *push, int med)
{
	int pa;
	int ra;
	int pb;

	pa = 0;
	ra = 0;
	pb = 0;
	while (ft_check_sort_lst(push->a) && push->b != NULL)
	{
		!push->count->len && !push->count->rb ? ft_del_first_stek(push) : 0;
		ft_if_rb(push);
		med = ft_med(push->b, 2, push->count->len);
		pa = ft_while_less_than_mad(push, med, pa);
		while (!ft_check_sort_lst(push->a) && pa > 3)
		{
			med = ft_med(push->a, 2, pa);
			ra += ft_while_more_than_mad(push, &med, &pa, &pb);
			ft_new_count(push);
			push->count->len = pb;
			pb = 0;
			ra = ft_while_ra(push, ra);
		}
		pa = 0;
		ft_sort_up_three(push);
	}
}
