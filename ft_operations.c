#include "ft_push_swap.h"

static	t_stek    *ft_del_first(t_stek *stek)
{
    stek = stek->next;

    free(stek->prev);
    stek->prev = NULL;
	return (stek);
}

void     ft_push(t_push *push, char n)
{
    if (n == 'a' && push->b)
    {
        if (!push->a)
            push->a = ft_makelst();
        else
        {
            push->a->prev = ft_makelst();
            push->a->prev->next = push->a;
            push->a = push->a->prev;
        }
        push->a->num = push->b->num;
        push->b = ft_del_first(push->b);
    }
    else if (n == 'b' && push->a)
    {
        if (!push->b)
            push->b = ft_makelst();
        else
        {
            push->b->prev = ft_makelst();
            push->b->prev->next = push->b;
            push->b = push->b->prev;
        }
        push->b->num = push->a->num;
        push->a = ft_del_first(push->a);
    }
}

void    ft_pswap(t_push *push, char n)
{
    int r;

    if (n == 'a' && push->a->next)
    {
        r = push->a->num;
        push->a->num = push->a->next->num;
        push->a->next->num = r;
    }
    else if (n == 'b' && push->b->next)
    {
        r = push->b->num;
        push->b->num = push->b->next->num;
        push->b->next->num = r;
    }
}

void    ft_rotate(t_push *push, char n)
{
    int c;

    if (n == 'a' && push->a && push->a->next)
    {
        c = push->a->num;
        while (push->a->next)
        {
            push->a->num = push->a->next->num;
            push->a = push->a->next;
        }
        push->a->num = c;
        while(push->a->prev)
            push->a = push->a->prev;
    }
    else if (n == 'b' && push->b && push->b->next)
    {
        c = push->b->num;
        while (push->b->next)
        {
            push->b->num = push->b->next->num;
            push->b = push->b->next;
        }
        push->b->num = c;
        while(push->b->prev)
            push->b = push->b->prev;
    }
}

void    ft_reverse_rotate(t_push *push, char n)
{
    int c;

    if (n == 'a' && push->a && push->a->next)
    {
        while (push->a->next)
            push->a = push->a->next;
        c = push->a->num;
        while (push->a->prev)
        {
            push->a->num = push->a->prev->num;
            push->a = push->a->prev;
        }
        push->a->num = c;
    }
    else if (n == 'b' && push->b && push->b->next)
    {
        while (push->b->next)
            push->b = push->b->next;
        c = push->b->num;
        while (push->b->prev)
        {
            push->b->num = push->b->prev->num;
            push->b = push->b->prev;
        }
        push->b->num = c;
    }
}