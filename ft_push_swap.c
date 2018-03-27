#include "ft_push_swap.h"

t_stek*  ft_makelst(void)
{
    t_stek *stek;

    stek = (t_stek*)malloc(sizeof(t_stek));
    stek->prev = NULL;
    stek->next = NULL;
    stek->num = 0;
    return (stek);
}

t_stek*     ft_read_args(int argc, char **argv)
{
    int i;
    int j;
    t_stek *stek;
    t_stek *node;

    stek = ft_makelst();
    node = stek;
    i = 1;
    while(i != argc)
    {
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

int 	ft_is_sort(char *arr)
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

int     main(int argc, char **argv)
{
    t_push *push;
	int med;

    push = (t_push*)malloc(sizeof(t_push));
    push->a = ft_read_args(argc, argv);
    push->b = NULL;
	med = ft_med(push->a, 2);
	ft_push_b(push, med);
}
