
#include "ft_push_swap.h"

static	int 	ft_is_sort(char *arr)
{
	int	i;

	i = 0;
	while(arr[i + 1])
	{
		if (arr[i] > arr[i + 1])
			return (0);
		else
			i++;
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

int 	*ft_med(t_stek *stek)
{
	char 	*arr;
	int 	med;

	arr = ft_make_arr(stek);
	med = arr[ft_strlen(arr) / 2] - '0';
	ft_strdel(&arr);
	return (med);
}