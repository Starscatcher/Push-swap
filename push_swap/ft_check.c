#include "ft_push_swap.h"

int	ft_check_sort_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while(i + 1 < size)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_check_sort_lst(t_stek *stek)
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

int	ft_more_then_med(t_stek *stek, int med)
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

int	ft_less_than_mad(t_stek *stek, int med)
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
