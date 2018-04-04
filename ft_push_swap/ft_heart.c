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

int		ft_find_less(t_stek *stek, int med)
{
	int little;
	int k;

	k = 0;
	if (stek->num < med && stek->num < stek->next->num)
		little = stek->num;
	else if (stek->next->num < med && stek->next->num < stek->num)
	{
		little = stek->next->num;
		k++;
	}
	while (stek->next)
		stek = stek->next;
	if (stek->num < little && stek->num < med)
		return (2);
	else
		return (k);
}

int		ft_push_b(t_push *push, int med, int secmed)
{
	int on;

	on = 0;
	while (ft_stek_len(push->a) > 3)
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

void	ft_sort_five(t_push *push, int med)
{
	while (!ft_more_then_med(push->a, med) && !ft_check_sort_lst(push->a))
	{
		if (ft_find_less(push->a, med) == 2)
			ft_reverse_rotate(push, 'a');
		if (push->a->num < med)
			ft_push(push, 'b');
		else if (push->a->num >= med)
			ft_rotate(push, 'a');
	}
	if (ft_stek_len(push->a) == 3)
		ft_sort_three(push);
	if (push->b->num < push->b->next->num)
		ft_pswap(push, 'b');
	while (push->b)
		ft_push(push, 'a');
}

int		ft_sort(t_push *push)
{
	int	med;
	int secmed;

	med = ft_med(push->a, 2, 0);
	secmed = ft_med(push->a, 4, 0);
	push->com = ft_strdup("");
	push->count = ft_make_count();
	if (ft_stek_len(push->a) == 1)
		return (1);
	if (ft_stek_len(push->a) <= 3)
		ft_sort_three(push);
	else if (ft_stek_len(push->a) < 6)
		ft_sort_five(push, med);
	else
	{
		med = ft_push_b(push, med, secmed);
		ft_push_a(push, med);
	}
	return (1);
}
