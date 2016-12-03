# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 19:44:10 by ariard            #+#    #+#              #
#    Updated: 2016/12/03 21:15:24 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC= main.c printf.c print_argument.c  parse_flag.c auxi_parse_flag.c rules_char_string.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_putnbr.c ./Libft/ft_strchrcpy.c ./Libft/ft_strcmp.c ./Libft/ft_strdel.c ./Libft/ft_strlenchr.c ./Libft/ft_strnew.c ./Libft/ft_bzero.c  ./Libft/ft_strchr.c  ./Libft/ft_strlen.c ./Libft/ft_intlen.c ./Libft/ft_memalloc.c ./Libft/ft_atoi.c ./Libft/ft_strncpy.c ./Libft/ft_putstrn.c

OBJ= main.o printf.o print_argument.o parse_flag.o auxi_parse_flag.o rules_char_string.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_strchrcpy.o ft_strcmp.o ft_strdel.o ft_strlenchr.o ft_strnew.o ft_bzero.o ft_strchr.o ft_strlen.o ft_intlen.o ft_memalloc.o ft_atoi.o ft_strncpy.o ft_putstrn.o

HEADER= ft_printf.h
FLAGS= #-Wall -Wextra -Werror

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


