/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:10:27 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/11 12:10:29 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_error_int(char **argv, int i)
{
	ssize_t num;

	num = ft_atoi(argv[i]);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	else
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

void	ft_error_digit(char **argv, int i)
{
	int j;

	j = 0;
	if (argv[i][j] == '-')
		j++;
	while (argv[i][j])
	{
		if (!ft_isdigit(argv[i][j]))
		{
			ft_putstr("Error\n");
			exit(1);
		}
		j++;
	}
}

int		ft_error_duplicates(t_stek *stek, t_push *push)
{
	t_stek *copy;

	while (stek)
	{
		copy = stek->next;
		while (copy)
		{
			if (copy->num == stek->num)
			{
				ft_stek_del(push);
				printf("Error\n");
				exit(1);
			}
			copy = copy->next;
		}
		stek = stek->next;
	}
	return (0);
}
