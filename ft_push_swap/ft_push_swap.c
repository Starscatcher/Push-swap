/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:52:11 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:52:12 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_commands(t_push *push, char *command, char n, int len)
{
	char *arr;

	arr = ft_strnew(2);
	arr[0] = n;
	arr[1] = '\n';
	push->com = ft_realloc(push->com, ft_strlen(push->com) + len);
	push->com = ft_strcat(push->com, command);
	push->com = ft_strcat(push->com, arr);
	ft_strdel(&arr);
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

t_stek	*ft_help_read(char **argv, t_stek *stek)
{
	int i;

	i = 0;
	while (argv[i])
	{
		ft_error_digit(argv, i);
		if (!ft_is_int(argv, i))
		{
			ft_putstr("Error\n");
			exit(1);
		}
		stek->num = ft_atoi(argv[i]);
		if (argv[i + 1])
		{
			stek->next = ft_makelst();
			stek->next->prev = stek;
			stek = stek->next;
		}
		i++;
	}
	return (stek);
}

t_stek	*ft_read_args(int argc, char **argv)
{
	int		i;
	char	**arguments;
	t_stek	*stek;
	t_stek	*node;

	stek = ft_makelst();
	if (argc == 1)
		exit(1);
	node = stek;
	i = 1;
	while (i < argc)
	{
		arguments = ft_strsplit(argv[i++], ' ');
		stek = ft_help_read(arguments, stek);
		if (i < argc)
		{
			stek->next = ft_makelst();
			stek->next->prev = stek;
			stek = stek->next;
		}
	}
	return (node);
}
