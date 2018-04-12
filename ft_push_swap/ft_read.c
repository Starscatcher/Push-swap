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

t_stek	*ft_help_read(char **argv, t_stek *stek)
{
	int i;

	i = 0;
	while (argv && argv[i])
	{
		ft_error_digit(argv, i);
		ft_error_int(argv, i);
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

void	ft_free_args(char **arguments)
{
	int i;
	int j;

	i = 0;
	while (arguments && arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
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
		ft_free_args(arguments);
	}
	return (node);
}
