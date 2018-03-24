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

int     main(int argc, char **argv)
{
    t_push *push;

    push = (t_push*)malloc(sizeof(t_push));
    push->a = ft_read_args(argc, argv);
    push->b = NULL;
	ft_med(push->a);
}
