
#include "ft_push_swap.h"

int 	ft_is_sort(t_stek *stek)
{
	while (stek)
	{
		if (stek->num > stek->next->num)
			return (0);
		else
			stek = stek->next;
	}
	return (1);
}

int 	ft_sort(t_push *push)
{
	int 	count;
	int 	med;

	med = ft_med(push->a);
	count = ft_lstlen(push->a);
	while(ft_is_sort(push->a) && push->b != NULL)
	{
		while ()
	}
}

