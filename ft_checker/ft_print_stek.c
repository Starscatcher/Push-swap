/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:43:32 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/11 14:43:33 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_print_elem(t_stek *stek, int on)
{
	while (stek && stek->next)
	{
		ft_printf("%d ", stek->num);
		stek = stek->next;
	}
	if (stek)
	{
		on ? ft_printf("{green}%d {eoc}", stek->num) : \
				ft_printf("%d ", stek->num);
	}
	ft_printf("\n");
}

void	ft_push_print(t_option *option, char *str, t_push *push)
{
	if (option->c && str)
		ft_commands_in_colour(option, str, push);
	else
	{
		ft_printf(" [ a ] | ");
		ft_print_elem(push->a, 0);
		ft_printf(" [ b ] | ");
		ft_print_elem(push->b, 0);
		ft_printf("\n");
	}
}
