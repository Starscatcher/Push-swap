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

void	ft_sort_three(t_push *push)
{
	while (!ft_check_sort_lst(push->a))
	{
		if (push->a->num > push->a->next->num)
			ft_pswap(push, 'a');
		if (push->a->num > push->a->next->next->num)
			ft_reverse_rotate(push, 'a');
		if (push->a->next->num > push->a->next->next->num)
			ft_reverse_rotate(push, 'a');
	}
}

void	ft_sort_up_three(t_push *push)
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
