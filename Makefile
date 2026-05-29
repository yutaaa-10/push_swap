# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yukurosa <yukurosa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/23 09:46:20 by yukurosa          #+#    #+#              #
#    Updated: 2026/05/29 14:29:59 by yukurosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -Ilibft

SRCS = \
	main.c \
	parse_args.c \
	parse_split.c\
	list.c \
	libft_split.c \
	libft_put.c \
	libft_utils.c \
	sort_route.c \
	sort_small.c \
	adaptive.c \
	error_check.c \
	sort_selection.c\
	sort_chunk.c \
	sort_chunk_help.c \
	sort_radix.c\
	oper_p.c \
	oper_r.c \
	oper_rr.c \
	oper_s.c \
	bench.c \
	bench_print.c 

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
