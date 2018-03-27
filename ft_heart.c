
#include "ft_push_swap.h"

t_count		*ft_make_count(void)
{
	t_count *count;

	count = (t_count*)malloc(sizeof(t_count));
	count->next = NULL;
	count->len = 0;
	return (count);
}

int 	ft_check(t_push *push, int med)
{
	t_stek *copy;

	copy = push->a;
	while (copy)
	{
		if (copy->num < med)
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
	secmed = ft_med(push->a, 4);
	push->count = ft_make_count();
	while (ft_stek_sort(push->a) || ft_lstlen(push->a) > 3)
	{
		if (ft_check(push, med))
			on = ft_new_med(&med, &secmed, push);
		if (push->a->num > med)
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
		if (push->a->num > push->a->next->next->num)
			ft_rotate(push, 'a');
		if (push->a->num > push->a->next->num)
			ft_pswap(push, 'a');
	}
}

int 	ft_sort(t_push *push)
{
	int 	count;
	int 	med;

	med = ft_med(push->a, 2);
	count = ft_lstlen(push->a);
	ft_push_b(push, med);
	while(ft_stek_sort(push->a) && push->b != NULL)
	{
		//	while ()
	}
}