# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 19:44:10 by ariard            #+#    #+#              #
#    Updated: 2016/12/05 16:23:40 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CC = gcc
CFLAGS= -Wall -Wextra -Werror -g

LC=ar rc
IC= ranlib

SRC= printf.c print_argument.c  parse_flag.c auxi_parse_flag.c rules_char_string.c rules_int.c rules_base.c auxi_rules.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_putnbr.c ./Libft/ft_strchrcpy.c ./Libft/ft_strcmp.c ./Libft/ft_strdel.c ./Libft/ft_strlenchr.c ./Libft/ft_strnew.c ./Libft/ft_bzero.c  ./Libft/ft_strchr.c  ./Libft/ft_strlen.c ./Libft/ft_intlen.c ./Libft/ft_memalloc.c ./Libft/ft_atoi.c ./Libft/ft_strncpy.c ./Libft/ft_putstrn.c ./Libft/ft_strrev.c ./Libft/ft_put_hex.c ./Libft/ft_put_oct.c ./Libft/ft_unsintlen.c ./Libft/ft_putunsnbr.c ./Libft/ft_put_hexmaj.c

SRC2= main.c printf.c print_argument.c  parse_flag.c auxi_parse_flag.c rules_char_string.c rules_int.c rules_base.c auxi_rules.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_putnbr.c ./Libft/ft_strchrcpy.c ./Libft/ft_strcmp.c ./Libft/ft_strdel.c ./Libft/ft_strlenchr.c ./Libft/ft_strnew.c ./Libft/ft_bzero.c  ./Libft/ft_strchr.c  ./Libft/ft_strlen.c ./Libft/ft_intlen.c ./Libft/ft_memalloc.c ./Libft/ft_atoi.c ./Libft/ft_strncpy.c ./Libft/ft_putstrn.c ./Libft/ft_strrev.c ./Libft/ft_put_hex.c ./Libft/ft_put_oct.c ./Libft/ft_unsintlen.c ./Libft/ft_putunsnbr.c ./Libft/ft_put_hexmaj.c

OBJ= printf.o print_argument.o parse_flag.o auxi_parse_flag.o rules_char_string.o rules_int.o rules_base.o auxi_rules.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_strchrcpy.o ft_strcmp.o ft_strdel.o ft_strlenchr.o ft_strnew.o ft_bzero.o ft_strchr.o ft_strlen.o ft_intlen.o ft_memalloc.o ft_atoi.o ft_strncpy.o ft_putstrn.o ft_strrev.o ft_put_hex.o ft_put_oct.o ft_unsintlen.o ft_putunsnbr.o ft_put_hexmaj.o

OBJ2= main.o printf.o print_argument.o parse_flag.o auxi_parse_flag.o rules_char_string.o rules_int.o rules_base.o auxi_rules.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_strchrcpy.o ft_strcmp.o ft_strdel.o ft_strlenchr.o ft_strnew.o ft_bzero.o ft_strchr.o ft_strlen.o ft_intlen.o ft_memalloc.o ft_atoi.o ft_strncpy.o ft_putstrn.o ft_strrev.o ft_put_hex.o ft_put_oct.o ft_unsintlen.o ft_putunsnbr.o ft_put_hexmaj.o

HEADER= ft_printf.h
FLAGS= #-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@ $(CC) $(FLAGS) -c $(SRC) -include $(HEADER)
	@ $(LC) $(NAME) $(OBJ)
	@ $(IC) $(NAME)

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean clean all

test: 
	@ make -C ./Libft fclean && make -C ./Libft
	@ make -C ./libft clean
	@ gcc -c $(FLAGS) $(SRC2)
	@ gcc $(OBJ2) -o $(NAME) -I $(HEADER)

clean-test:
	@ rm -rf $(OBJ2)

fclean-test: clean-test
	@ rm -f $(NAME)
	@ rm -f Libft/libft.a

re-test: fclean-test test
