/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_med.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:51:35 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:51:35 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			ft_new_med(int *med, t_push *push)
{
	ft_new_count(push);
	*med = ft_med(push->a, 2, 0);
	return (1);
}

static int	*ft_sort_arr(int *arr, int size)
{
	int swap;
	int i;

	i = 0;
	while (!ft_check_sort_arr(arr, size))
	{
		if (i + 1 == size)
			i = 0;
		if (arr[i] > arr[i + 1])
		{
			swap = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = swap;
		}
		i++;
	}
	return (arr);
}

static int	*ft_make_arr(t_stek *stek, int where, int *size)
{
	int *arr;
	int i;
	int len;

	i = 0;
	len = where <= 0 ? ft_stek_len(stek) : where;
	*size = len;
	arr = (int *)malloc(sizeof(int) * *size);
	while (stek && len > 0)
	{
		arr[i++] = stek->num;
		stek = stek->next;
		len--;
	}
	arr = ft_sort_arr(arr, *size);
	return (arr);
}

int			ft_med(t_stek *stek, int num, int where)
{
	int *arr;
	int med;
	int size;

	arr = ft_make_arr(stek, where, &size);
	med = arr[size / num];
	free(arr);
	return (med);
}
