
#include "ft_push_swap.h"

t_push	*ft_add_end(int secmed, t_push *push)
{
	int count;
	t_stek *copy;
	t_count *add;

	count = 0;
	copy = push->b;
	add = (t_count*)malloc(sizeof(t_count));
	while(copy->num >= secmed)
		copy = copy->next;
	while (copy && copy->num < secmed)
	{
		count++;
		copy = copy->next;
	}
	push->count->next->next = add;
	push->count->next->len = push->count->next->len - count;
	push->count->next->next->len = count;
	push->count->next->next->rb = 0;
	push->count->next->next->next = NULL;
	return (push);
}

void	ft_push_b(t_push *push, int med)
{
	int	secmed;
	int on;

	on = 0;
	secmed = ft_med(push->a, 4, 0);
	while (!ft_check_sort_lst(push->a) && ft_lstlen(push->a) > 3)
	{
		if (ft_more_then_med(push->a, med))
		{
			ft_new_med(&med, push);
			on++;
		}
		if (on == 1)
		{
			ft_add_end(secmed, push);
			on++;
		}
		if (!ft_more_then_med(push->a, med) && push->a->num >= med)
			ft_rotate(push, 'a');
		else
		{
			ft_push(push, 'b');
			if (!on && push->b->num < secmed && push->b->next)
				ft_rotate(push, 'b');
			push->count->len++;
		}
	}
	ft_sort_three(push);
}

void	ft_push_a(t_push *push)
{
	int med;
	int pa;
	int ra;
	int pb;

	pa = 0;
	ra = 0;
	pb = 0;
	while(ft_check_sort_lst(push->a) && push->b != NULL)
	{
		if (!push->count->len && !push->count->rb)
		{
			ft_del_first_stek(push);
		}
		if (push->count && push->count->rb)
		{
			while (push->count->rb > 0)
			{
				ft_reverse_rotate(push, 'b');
				push->count->rb--;
			}
		}
		med = ft_med(push->b, 2, push->count->len);
		while (!ft_less_than_mad(push->b, med))
		{
			if (push->b->num >= med)
			{
				ft_push(push, 'a');
				pa++;
				push->count->len--;
			}
			else
			{
				ft_rotate(push, 'b');
				push->count->rb++;
			}
		}
		while (!ft_check_sort_lst(push->a) && pa > 3)
		{
			med = ft_med(push->a, 2, pa);
			while (!ft_more_then_med(push->a, med))
			{
				if (push->a->num >= med)
				{
					ft_rotate(push, 'a');
					ra++;
				}
				else
				{
					ft_push(push, 'b');
					pb++;
					pa--;
				}
			}
			ft_new_count(push);
			push->count->len = pb;
			pb = 0;
			while (ra > 0)
			{
				ft_reverse_rotate(push, 'a');
				ra--;
			}
		}
		pa = 0;
		!ft_check_sort_lst(push->a) ? ft_sort_up_three(push) : 0;
	}
}

int 	ft_sort(t_push *push)
{
	int 	med;

	med = ft_med(push->a, 2, 0);
	push->command = ft_strdup("");
	push->count = ft_make_count();
	push->fin = 0;
	ft_push_b(push, med);
	ft_push_a(push);
}