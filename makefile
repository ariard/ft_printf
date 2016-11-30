# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 19:44:10 by ariard            #+#    #+#              #
#    Updated: 2016/11/30 20:26:08 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC= main.c ft_printf.c
OBJ= main.o ft_printf.o
HEADER= ft_printf.h
FLAGS= -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@ make -C ./Libft fclean && make -C ./Libft
	@ make -C ./libft clean
	@ gcc -c $(FLAGS) $(SRC)
	@ gcc $(OBJ) -o $(NAME) -I $(HEADER)

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -f $(NAME)
	@ rm -f Libft/libft.a

re: fclean all
