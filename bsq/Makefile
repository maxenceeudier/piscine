# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 15:49:56 by meudier           #+#    #+#              #
#    Updated: 2022/03/30 16:19:04 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = ft_atoi.o ft_check_file.o ft_get_data_and_map.o ft_get_file.o ft_split.o \
	init_free_and_print.o main.o solve.o tools_and_mini.o

NAME = bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ft.h  $(OBJS) -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) rush.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
