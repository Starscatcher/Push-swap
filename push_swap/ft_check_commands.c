/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:51:24 by aryabenk          #+#    #+#             */
/*   Updated: 2018/03/31 13:51:25 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_add(char *com, char *find, char *replace)
{
	int		i;
	char	*temp;

	i = 0;
	if ((temp = ft_strstr(com, find)))
	{
		while (replace[i])
		{
			temp[i] = replace[i];
			i++;
		}
	}
	return (i);
}

void	ft_make_new_arr(t_push *push)
{
	char	*newarr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (push->com[i])
		push->com[i++] == '-' ? 0 : j++;
	newarr = ft_strnew(j);
	i = 0;
	j = 0;
	while (push->com[i])
	{
		if (push->com[i] == '-')
			i++;
		else
			newarr[j++] = push->com[i++];
	}
	ft_strdel(&push->com);
	push->com = newarr;
}

void	ft_rewrite_commands(t_push *push)
{
	int		k;

	k = 1;
	while (k > 0)
	{
		k = ft_add(push->com, "\nsa\nsb\n", "\nss\n---");
		k += ft_add(push->com, "\nsb\nsa\n", "\nss\n---");
		k += ft_add(push->com, "\nra\nrb\n", "\nrr\n---");
		k += ft_add(push->com, "\nrb\nra\n", "\nrr\n---");
		k += ft_add(push->com, "\npa\npb\n", "\n------");
		k += ft_add(push->com, "\npb\npa\n", "\n------");
		k += ft_add(push->com, "\nrra\nrrb\n", "\nrrr\n----");
		k += ft_add(push->com, "\nrrb\nrra\n", "\nrrr\n----");
		k += ft_add(push->com, "\nrra\nra\n", "\n-------");
		k += ft_add(push->com, "\nrrb\nrb\n", "\n-------");
		k += ft_add(push->com, "\nra\npb\nrra\n", "\nsa\npb\n----");
		k += ft_add(push->com, "\nrb\npa\nrrb\n", "\nsb\npa\n----");
		k ? ft_make_new_arr(push) : 0;
	}
}
