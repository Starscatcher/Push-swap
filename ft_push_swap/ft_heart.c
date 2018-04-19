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

int		ft_sort(t_push *push)
{
	int	med;
	int secmed;

	med = ft_med(push->a, 2, 0);
	secmed = ft_med(push->a, 4, 0);
	push->com = ft_strdup("");
	push->count = ft_make_count();
	if (ft_stek_len(push->a) == 1 || ft_check_sort_lst(push->a))
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
