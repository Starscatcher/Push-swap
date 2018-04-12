/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:31:52 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/11 12:31:52 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_commands(t_push *push, char *command, char n, int len)
{
	char	*arr;

	arr = ft_strnew(2);
	arr[0] = n;
	arr[1] = '\n';
	push->com = ft_realloc(push->com, ft_strlen(push->com) + len);
	push->com = ft_strcat(push->com, command);
	push->com = ft_strcat(push->com, arr);
	ft_strdel(&arr);
}
