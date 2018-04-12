/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:28:01 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/11 12:28:01 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stek_del(t_push *push)
{
	t_stek	*copy;

	if (push->com)
		ft_strdel(&push->com);
	if (push->count)
		free(push->count);
	if (push->a)
	{
		while (push->a)
		{
			copy = push->a->next;
			free(push->a);
			push->a = copy;
		}
	}
	if (push->b)
	{
		while (push->b)
		{
			copy = push->b->next;
			free(push->b);
			push->b = copy;
		}
	}
	free(push);
}
