
#include "ft_push_swap.h"

t_count		*ft_make_count(void)
{
	t_count *count;

	count = (t_count*)malloc(sizeof(t_count));
	count->next = NULL;
	count->len = 0;
	count->rb = 0;
	return (count);
}

int 	ft_stek_sort(t_stek *stek)
{
	while (stek && stek->next)
	{
		if (stek->num > stek->next->num)
			return (0);
		else
			stek = stek->next;
	}
	return (1);
}

int 	ft_check(t_stek *stek, int med)
{
	t_stek *copy;

	copy = stek;
	while (copy)
	{
		if (copy->num < med)
			return (0);
		copy = copy->next;
	}
	return (1);
}

int 	ft_less_than_mad(t_stek *stek, int med)
{
	t_stek *copy;

	copy = stek;
	while (copy)
	{
		if (copy->num >= med)
			return (0);
		copy = copy->next;
	}
	return (1);
}

void	ft_push_b(t_push *push, int med)
{
	int	secmed;
	int on;

	on = 0;
	secmed = ft_med(push->a, 4, 0);
	push->count = ft_make_count();
	while (!ft_stek_sort(push->a) || ft_lstlen(push->a) > 3)
	{
		if (ft_check(push->a, med))
			on = ft_new_med(&med, push);
		if (push->a->num >= med)
			ft_rotate(push, 'a');
		else
		{
			ft_push(push, 'b');
			if (!on && push->b->num < secmed)
				ft_rotate(push, 'b');
			push->count->len++;
		}
	}
	while (!ft_stek_sort(push->a))
	{
		if (push->a->num > push->a->next->num)
			ft_pswap(push, 'a');
		if (push->a->num > push->a->next->next->num)
			ft_reverse_rotate(push, 'a');
		if (push->a->next->num > push->a->next->next->num)
			ft_reverse_rotate(push, 'a');
	}
}

void	ft_sort_three(t_push *push)
{
	while (!ft_stek_sort(push->a))
	{
		if (push->a->num > push->a->next->num)
			ft_pswap(push, 'a');
		if (push->a->next->num > push->a->next->next->num)
		{
			ft_rotate(push, 'a');
			ft_pswap(push, 'a');
			ft_reverse_rotate(push, 'a');
		}
		if (push->a->num > push->a->next->next->num)
		{
			ft_rotate(push, 'a');
			ft_pswap(push, 'a');
			ft_reverse_rotate(push, 'a');
			ft_pswap(push, 'a');
		}
	}
}

void	ft_del_first_stek(t_push *push)
{
	t_count *first;
	t_count *second;

	first = push->count;
	second = push->count->next;
	push->count = second;
	free(first);
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
	while(ft_stek_sort(push->a) && push->b != NULL)
	{
		if (!push->count->len && !push->count->rb)
		{
			ft_del_first_stek(push);
		}
		if (push->count->rb)
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
		while (!ft_stek_sort(push->a) && pa > 3)
		{
			med = ft_med(push->a, 2, pa);
			while (!ft_check(push->a, med))
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
		!ft_stek_sort(push->a) ? ft_sort_three(push) : 0;
	}
}

int 	ft_sort(t_push *push)
{
	int 	count;
	int 	med;

	med = ft_med(push->a, 2, 0);
	count = ft_lstlen(push->a);
	ft_push_b(push, med);
	ft_push_a(push);

}