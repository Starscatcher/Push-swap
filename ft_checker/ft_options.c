/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:05:29 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/11 14:05:30 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

t_option	*ft_create_option(t_option *option)
{
	option = (t_option*)malloc(sizeof(t_option));
	option->c = 0;
	option->n = 0;
	option->v = 0;
	option->h = 0;
	option->l = 0;
	option->k = 0;
	return (option);
}

int			ft_find(char *arr, char elem)
{
	int j;

	j = 0;
	while (arr && arr[j])
	{
		if (arr[j] == elem)
			return (1);
		j++;
	}
	return (0);
}

int			ft_is_option(char f, char s)
{
	if (f != '-')
		return (0);
	if (ft_find("vcnlhk", s))
		return (1);
	else
		return (0);
}

char		**ft_find_option(int *argc, char **argv, t_option *option)
{
	int i;

	i = 1;
	while (i < *argc && ft_is_option(argv[i][0], argv[i][1]) && !argv[i][2])
	{
		option->c += argv[i][1] == 'c' ? 1 : 0;
		option->n += argv[i][1] == 'n' ? 1 : 0;
		option->v += argv[i][1] == 'v' ? 1 : 0;
		option->h += argv[i][1] == 'h' ? 1 : 0;
		option->l += argv[i][1] == 'l' ? 1 : 0;
		option->k += argv[i][1] == 'k' ? 1 : 0;
		i++;
		--*argc;
	}
	return (argv + i - 1);
}
