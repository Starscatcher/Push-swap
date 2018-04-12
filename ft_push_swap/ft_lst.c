/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:51:52 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:51:52 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

size_t	ft_stek_len(t_stek *stek)
{
	size_t count;

	count = 0;
	if (stek == NULL)
		return (0);
	while (stek)
	{
		stek = stek->next;
		count++;
	}
	return (count);
}

t_stek	*ft_makelst(void)
{
	t_stek *stek;

	stek = (t_stek*)malloc(sizeof(t_stek));
	stek->prev = NULL;
	stek->next = NULL;
	stek->num = 0;
	return (stek);
}

void	ft_del_first_stek(t_push *push)
{
	t_count *first;
	t_count *second;

	first = push->count;
	second = push->count->next;
	push->count = second;
	free(first);
}

t_count	*ft_make_count(void)
{
	t_count *count;

	count = (t_count*)malloc(sizeof(t_count));
	count->next = NULL;
	count->len = 0;
	count->rb = 0;
	return (count);
}

void	ft_new_count(t_push *push)
{
	t_count *new;

	new = ft_make_count();
	new->next = push->count;
	push->count = new;
}
