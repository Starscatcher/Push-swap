#include "ft_push_swap.h"

int	ft_add_in_arr(char *arr, char *word)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (word[j])
		arr[i++] = word[j++];
	return (1);
}

void	ft_make_new_arr(t_push *push)
{
	char	*newarr;
	int i;
	int size;
	int j;

	i = 0;
	j = 0;
	size = 0;
	while (push->command[i])
		push->command[i++] == '-' ? 0 : size++;
	newarr = ft_strnew(size);
	i = 0;
	while (push->command[i])
	{
		if (push->command[i] == '-')
			i++;
		else
			newarr[j++] = push->command[i++];
	}
	ft_strdel(&push->command);
	push->command = newarr;
}

void	ft_rewrite_commands(t_push *push)
{
	char *tmp;
	int done;

	done = 1;
	while (done > 0)
	{
		done = (tmp = ft_strstr(push->command, "\nsa\nsb\n")) ? ft_add_in_arr(tmp, "\nss\n---") : 0;
		done += (tmp = ft_strstr(push->command, "\nsb\nsa\n")) ? ft_add_in_arr(tmp, "\nss\n---") : 0;
		done += (tmp = ft_strstr(push->command, "\nra\nrb\n")) ? ft_add_in_arr(tmp, "\nrr\n---") : 0;
		done += (tmp = ft_strstr(push->command, "\nrb\nra\n")) ? ft_add_in_arr(tmp, "\nrr\n---") : 0;
		done += (tmp = ft_strstr(push->command, "\npa\npb\n")) ? ft_add_in_arr(tmp, "\n------") : 0;
		done += (tmp = ft_strstr(push->command, "\npb\npa\n")) ? ft_add_in_arr(tmp, "\n------") : 0;
		done += (tmp = ft_strstr(push->command, "\nrra\nrrb\n")) ? ft_add_in_arr(tmp, "\nrrr\n----") : 0;
		done += (tmp = ft_strstr(push->command, "\nrrb\nrra\n")) ? ft_add_in_arr(tmp, "\nrrr\n----") : 0;
		done += (tmp = ft_strstr(push->command, "\nrra\nra\n")) ? ft_add_in_arr(tmp, "\n-------") : 0;
		done += (tmp = ft_strstr(push->command, "\nrrb\nrb\n")) ? ft_add_in_arr(tmp, "\n-------") : 0;
		done += (tmp = ft_strstr(push->command, "\nra\npb\nrra\n")) ? ft_add_in_arr(tmp, "\nsa\npb\n----") : 0;
		done += (tmp = ft_strstr(push->command, "\nrb\npa\nrrb\n")) ? ft_add_in_arr(tmp, "\nsb\npa\n----") : 0;
		done ? ft_make_new_arr(push) : 0;
	}
}

