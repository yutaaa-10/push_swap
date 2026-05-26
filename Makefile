# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdobashi <hdobashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 09:46:20 by yukurosa          #+#    #+#              #
#    Updated: 2026/05/26 20:14:22 by hdobashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -Ilibft

SRCS = \
	main.c \
	input_parser/parse_args.c \
	input_parser/fill_index.c\
	stack/list.c \
	operation/operations.c \
	libft/ft_atoi.c \
	libft/ft_isdigit.c \
	libft/ft_strncmp.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_printf_Hexadecimal.c \
	ft_printf/ft_printf_number.c \
	ft_printf/ft_printf_utils.c \
	sort/route_sort.c \
	sort/small_sort.c \
	disoder/adaptive.c \
	error/error.c \
	error/has_duplicate.c \
	error/number_check.c \
	sort/simple_sort/selection.c\
	sort/medium_sort/a.c \
	sort/complex_sort/a.c





OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
