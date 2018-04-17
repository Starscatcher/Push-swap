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
	char	com;

	com = ft_find_command(str);
	if ((option->c) && str)
		ft_commandsincol(option, str, push, 0);
	else
	{
		ft_printf(" [ a ] ");
		if (option->k && (com == 'a' || com == 't'))
			ft_print_command(str);
		else if (option->k)
			ft_printf("      | ");
		else
			ft_printf("| ");
		ft_print_elem(push->a, 0);
		ft_printf(" [ b ] ");
		if (option->k && (com == 'b' || com == 't'))
			ft_print_command(str);
		else if (option->k)
			ft_printf("      | ");
		else
			ft_printf("| ");
		ft_print_elem(push->b, 0);
		ft_printf("\n");
	}
}
