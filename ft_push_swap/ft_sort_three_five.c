/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:52:24 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:52:25 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_num(t_stek *stek, int index)
{
	int i;

	i = 0;
	if (index < 0)
	{
		while (stek && stek->next)
			stek = stek->next;
		return (stek->num);
	}
	while (stek && stek->next && i < index)
	{
		i++;
		stek = stek->next;
	}
	return (stek->num);
}

void		ft_sort_three(t_push *push)
{
	while (!ft_check_sort_lst(push->a))
	{
		if (push->a->num > push->a->next->num && push->a->num > ft_num(push->a, -1))
			ft_rotate(push, 'a');
		if (push->a->num > push->a->next->num)
			ft_pswap(push, 'a');
		if (push->a->num > ft_num(push->a, -1))
			ft_reverse_rotate(push, 'a');
		if (push->a->next->num > ft_num(push->a, -1))
			ft_reverse_rotate(push, 'a');
	}
	!ft_check_sort_lst(push->a) ? ft_pswap(push, 'a') : 0;
}

void		ft_sort_up_three(t_push *push)
{
	while (!ft_check_sort_lst(push->a))
	{
		if (push->a->num > push->a->next->num)
			ft_pswap(push, 'a');
		if (push->a->next->num > push->a->next->next->num)
		{
			ft_rotate(push, 'a');
			ft_pswap(push, 'a');
			ft_reverse_rotate(push, 'a');
		}
		if (push->a->num > push->a->next->next->num)
		{
			ft_rotate(push, 'a');
			ft_pswap(push, 'a');
			ft_reverse_rotate(push, 'a');
			ft_pswap(push, 'a');
		}
	}
}

static	int	ft_find_less(t_stek *stek, int med)
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

void		ft_sort_five(t_push *push, int med)
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
