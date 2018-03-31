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
	char *narr;

	narr = ft_strnew(2);
	narr[0] = n;
	narr[1] = '\n';
	push->com = ft_realloc(push->com, ft_strlen(push->com) + len);
	push->com = ft_strcat(push->com, command);
	push->com = ft_strcat(push->com, narr);
	push->fin++;
}

t_stek	*ft_read_args(int argc, char **argv)
{
	int		i;
	int 	j;
	t_stek	*stek;
	t_stek	*node;

	stek = ft_makelst();
	node = stek;
	i = 1;
	while (i != argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j++]))
			{
				printf("Error");
				exit(1);
			}
		}
		stek->num = ft_atoi(argv[i++]);
		if (i != argc)
		{
			stek->next = ft_makelst();
			stek->next->prev = stek;
			stek = stek->next;
		}
	}
	return (node);
}


int		main(int argc, char **argv)
{
	t_push	*push;
	int		med;
	int		fd;

	push = (t_push*)malloc(sizeof(t_push));
	push->a = ft_read_args(argc, argv);
	ft_find_error(push->a);
	push->b = NULL;
	ft_sort(push);
	ft_rewrite_commands(push);
	fd = open("../1", O_RDWR);
	ft_putstr_fd(push->com, fd);

}
