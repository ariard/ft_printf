# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 19:44:10 by ariard            #+#    #+#              #
#    Updated: 2016/12/01 18:43:32 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC= main.c printf.c print_argument.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_putnbr.c ./Libft/ft_strchrcpy.c ./Libft/ft_strcmp.c ./Libft/ft_strdel.c ./Libft/ft_strlenchr.c ./Libft/ft_strnew.c ./Libft/ft_bzero.c  ./Libft/ft_strchr.c

OBJ= main.o printf.o print_argument.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_strchrcpy.o ft_strcmp.o ft_strdel.o ft_strlenchr.o ft_strnew.o ft_bzero.o ft_strchr.o

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

test-parsing:
	@ make -C ./Libft fclean && make -C ./Libft
	@ make -C ./libft clean
	@ gcc -c $(FLAGS) $(SRC2)
	@ gcc $(OBJ2) -o $(NAME) -I $(HEADER)


