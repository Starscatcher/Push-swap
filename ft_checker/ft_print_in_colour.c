/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_in_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:33:09 by aryabenk          #+#    #+#             */
/*   Updated: 2018/04/12 16:33:10 by aryabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

char	ft_find_colour(char *str)
{
	if (ft_strequ("pa", str) || ft_strequ("pb", str))
		return ('b');
	else if (ft_strequ("sa", str) || ft_strequ("sb", str) || \
			ft_strequ("ss", str))
		return ('v');
	else if (ft_strequ("ra", str) || ft_strequ("rb", str) || \
			ft_strequ("rr", str))
		return ('g');
	else if (ft_strequ("rra", str) || ft_strequ("rrb", str) || \
			ft_strequ("rrr", str))
		return ('y');
	return (0);
}

void	ft_print_command(char *str)
{
	char col;

	col = ft_find_colour(str);
	col == 'b' ? ft_printf(" {blue}->%s{eoc} | ", str) : 0;
	col == 'v' ? ft_printf(" {violet}->%s{eoc} | ", str) : 0;
	col == 'g' ? ft_printf(" {green}->%s{eoc} | ", str) : 0;
	col == 'y' ? ft_printf("{yellow}->%s{eoc} | ", str) : 0;
}

void	ft_push_in_colour(char *str, t_stek *stek)
{
	if (!stek)
	{
		ft_printf("\n");
		return ;
	}
	if ((ft_strequ("pa", str) || ft_strequ("pb", str)))
		ft_printf("{blue}%d{eoc} ", stek->num);
	else if ((ft_strequ("sa", str) || ft_strequ("sb", str) || \
			ft_strequ("ss", str)))
	{
		if (!stek->next)
		{
			ft_printf("\n");
			return ;
		}
		ft_printf("{violet}%d{eoc} ", stek->num);
		stek = stek->next;
		ft_printf("{violet}%d{eoc} ", stek->num);
	}
	else if (ft_strequ("rra", str) || ft_strequ("rrb", str) || \
			ft_strequ("rrr", str))
		ft_printf("{yellow}%d{eoc} ", stek->num);
	ft_strequ("ra", str) || ft_strequ("rb", str) || ft_strequ("rr", str) \
		? ft_print_elem(stek, 1) : ft_print_elem(stek->next, 0);
}

char	ft_find_command(char *str)
{
	if (ft_strequ(str, "sa") || ft_strequ(str, "pa") || ft_strequ(str, "ra"))
		return ('a');
	if (ft_strequ(str, "rra"))
		return ('a');
	if (ft_strequ(str, "sb") || ft_strequ(str, "pb") || ft_strequ(str, "rb"))
		return ('b');
	if (ft_strequ(str, "rrb"))
		return ('b');
	else
		return ('t');
}

void	ft_commandsincol(t_option *option, char *str, t_push *push, int on)
{
	on = ft_find_command(str);
	ft_printf(" [ a ] ");
	if (on == 'a' || on == 't')
	{
		option->k ? ft_print_command(str) : ft_printf("| ");
		ft_push_in_colour(str, push->a);
	}
	else
	{
		ft_printf("%*s ", option->k ? 7 : 0, "|");
		ft_print_elem(push->a, 0);
	}
	ft_printf(" [ b ] ");
	if (on == 'b' || on == 't')
	{
		option->k ? ft_print_command(str) : ft_printf("| ");
		ft_push_in_colour(str, push->b);
	}
	else
	{
		ft_printf("%*s ", option->k ? 7 : 0, "|");
		ft_print_elem(push->b, 0);
	}
	ft_printf("\n");
}
