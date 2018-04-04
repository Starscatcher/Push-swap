#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aryabenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 16:40:55 by aryabenk          #+#    #+#              #
#    Updated: 2018/03/13 16:40:56 by aryabenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_CH = checker

NAME_PS = push_swap

SRC_PS = ./ft_push_swap/ft_check.c ./ft_push_swap/ft_check_commands.c \
            ./ft_push_swap/ft_find_med.c ./ft_push_swap/ft_heart.c \
            ./ft_push_swap/ft_lst.c ./ft_push_swap/ft_operations.c \
            ./ft_push_swap/ft_push_swap.c ./ft_push_swap/ft_stek_a.c \
            ./ft_push_swap/ft_three_sort.c ./ft_push_swap/ft_rotate_and_reverse.c \
            ./ft_push_swap/ft_start.c

SRC_CH = ./ft_checker/ft_check_operations.c ./ft_checker/ft_read.c \
            ./ft_push_swap/ft_check.c ./ft_push_swap/ft_operations.c \
            ./ft_push_swap/ft_lst.c ./ft_push_swap/ft_push_swap.c \
            ./ft_push_swap/ft_find_med.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME_CH) $(NAME_PS)

$(NAME_CH): $(SRC_CH)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC_CH) $(LIB) -o $(NAME_CH)

$(NAME_PS): $(SRC_PS)
	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC_PS) $(LIB) -o $(NAME_PS)

clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CH)
	$(MLIB) fclean

re: fclean all