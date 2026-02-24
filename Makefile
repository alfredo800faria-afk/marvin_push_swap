# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srusso-b <srusso-b@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 10:17:31 by srusso-b          #+#    #+#              #
#    Updated: 2026/02/23 05:26:38 by srusso-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

SRCS = push_swap.c sort.c push.c rev_rotate.c rotate.c swap_op.c utils_sort.c \
				parse_args.c utils_parse.c utils.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test test_edge test_checker
