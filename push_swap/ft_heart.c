/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:51:43 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:51:44 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_add_end(int secmed, t_push *push)
{
	int		count;
	t_stek	*copy;
	t_count	*add;

	count = 0;
	copy = push->b;
	add = (t_count*)malloc(sizeof(t_count));
	while (copy->num >= secmed)
		copy = copy->next;
	while (copy && copy->num < secmed)
	{
		count++;
		copy = copy->next;
	}
	push->count->next->next = add;
	push->count->next->len = push->count->next->len - count;
	push->count->next->next->len = count;
	push->count->next->next->rb = 0;
	push->count->next->next->next = NULL;
	return (1);
}

int		ft_push_b(t_push *push, int med, int secmed)
{
	int on;

	on = 0;
	while (!ft_check_sort_lst(push->a) && ft_lstlen(push->a) > 3)
	{
		if (ft_more_then_med(push->a, med))
			on += ft_new_med(&med, push);
		if (on == 1)
			on += ft_add_end(secmed, push);
		if (!ft_more_then_med(push->a, med) && push->a->num >= med)
			ft_rotate(push, 'a');
		else
		{
			ft_push(push, 'b');
			if (!on && push->b->num < secmed && push->b->next)
				ft_rotate(push, 'b');
			push->count->len++;
		}
	}
	ft_sort_three(push);
	return (med);
}

int		ft_sort(t_push *push)
{
	int	med;
	int secmed;

	med = ft_med(push->a, 2, 0);
	secmed = ft_med(push->a, 4, 0);
	push->com = ft_strdup("");
	push->count = ft_make_count();
	push->fin = 0;
	med = ft_push_b(push, med, secmed);
	ft_push_a(push, med);
}
