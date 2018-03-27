
#include "ft_push_swap.h"

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

static	char 	*ft_sort_arr(char *arr)
{
	char 	swap;
	int		i;

	i = 0;
	while (!ft_is_sort(arr))
	{
		if (!arr[i + 1])
			i = 0;
		if (arr[i] > arr[i + 1])
		{
			swap = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = swap;
		}
		i++;
	}
	return (arr);
}

static	char 	*ft_make_arr(t_stek *stek)
{
	char	*arr;
	int		size;
	int		i;

	i = 0;
	size = ft_lstlen(stek);
	arr = ft_strnew(size);
	while(stek)
	{
		arr[i++] = stek->num + '0';
		stek = stek->next;
	}
	arr = ft_sort_arr(arr);
	return (arr);
}

int 	ft_new_med(int *med, int *secmed, t_push *push)
{
	t_count *new;

	new = ft_make_count();
	new->next = push->count;
	push->count = new;
	*med = ft_med(push->a, 2);
	*secmed = ft_med(push->a, 4);
	return (1);
}

int 	ft_med(t_stek *stek, int num)
{
	char 	*arr;
	char 	med;

	arr = ft_make_arr(stek);
	med = arr[ft_strlen(arr) / num] - '0';
	ft_strdel(&arr);
	return (med);
}