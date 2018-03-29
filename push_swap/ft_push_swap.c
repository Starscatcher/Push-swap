#include "ft_push_swap.h"

t_stek*     ft_read_args(int argc, char **argv)
{
    int i;
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
	int med;

    push = (t_push*)malloc(sizeof(t_push));
    push->a = ft_read_args(argc, argv);
    push->b = NULL;
	ft_sort(push);
    ft_rewrite_commands(push);
    int fd = open("../1", O_RDWR);
    ft_putstr_fd(push->command, fd);
}
