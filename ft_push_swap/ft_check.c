/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:51:16 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:51:17 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_int(char **argv, int i)
{
	ssize_t	num;

	num = ft_atoi(argv[i]);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	else
		return (0);
}

int	ft_check_sort_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (arr[i] && i + 1 < size)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_check_sort_lst(t_stek *stek)
{
	while (stek && stek->next)
	{
		if (stek->num > stek->next->num)
			return (0);
		else
			stek = stek->next;
	}
	return (1);
}

int	ft_more_then_med(t_stek *stek, int med)
{
	t_stek *copy;

	copy = stek;
	while (copy)
	{
		if (copy->num < med)
			return (0);
		copy = copy->next;
	}
	return (1);
}

int	ft_less_than_mad(t_stek *stek, int med)
{
	t_stek *copy;

	copy = stek;
	while (copy)
	{
		if (copy->num >= med)
			return (0);
		copy = copy->next;
	}
	return (1);
}
