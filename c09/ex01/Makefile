# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 13:37:47 by meudier           #+#    #+#              #
#    Updated: 2022/03/24 14:50:04 by meudier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =gcc
FLAGS =-Wall -Wextra -Werror
OBJ =srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
FINAL =libft.a
INC =./includes/

all: $(FINAL)

$(FINAL): $(OBJ)
	ar -crs $(FINAL) $^ 
	
$(OBJ): %.o: %.c
	$(CC) -I$(INC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(FINAL)

re: fclean all
