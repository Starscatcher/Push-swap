#include "ft_push_swap.h"

int	*ft_quick_sort(int *arr, int start, int end)
{
	int d;
	int k;
	int len;
	int count;

	d = arr[end / 2];
	count = end / 2;
	len = end;
	while (!ft_check_sort_arr(arr, end))
	{
		start = 0;
		while (arr[start] && end >= 0)
		{
			if (arr[start] > d)
			{
				while (arr[end] >= d && end <= len)
				{
					if (arr[end] < arr[end - 1])
					{
						k = arr[end - 1];
						arr[end - 1] = arr[end];
						arr[end] = k;
					}
					end--;
				}
				if (arr[end] < d)
				{
					k = arr[start];
					arr[start] = arr[end];
					arr[end] = k;
				}
			}
			if (arr[start + 1] && arr[start] > arr[start + 1])
			{
				k = arr[start];
				arr[start] = arr[start + 1];
				arr[start + 1] = k;
			}
			start++;
		}
		end = len;
		if (count + 1 <= len)
			d = arr[++count];
	}
	return (arr);
}

