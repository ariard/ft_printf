# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 19:44:10 by ariard            #+#    #+#              #
#    Updated: 2016/12/09 13:57:32 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CC = gcc
CFLAGS= -Wall -Wextra -Werror -g

LC=ar rc
IC= ranlib

SRC= printf.c print_argument.c  parse_flag.c auxi_parse_flag.c distribute_invalid.c distribute_pourcent.c distribute_char.c distribute_string.c distribute_int.c distribute_long.c distribute_uns.c distribute_oct.c distribute_hex.c distribute_hexmaj.c distribute_pointer.c distribute_wchar.c distribute_wstring.c auxi_rules.c auxi_rules2.c auxi_rules3.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_putnbr.c ./Libft/ft_strchrcpy.c ./Libft/ft_strcmp.c ./Libft/ft_strdel.c ./Libft/ft_strlenchr.c ./Libft/ft_strnew.c ./Libft/ft_bzero.c  ./Libft/ft_strchr.c  ./Libft/ft_strlen.c ./Libft/ft_intlen.c ./Libft/ft_memalloc.c ./Libft/ft_atoi.c ./Libft/ft_strncpy.c ./Libft/ft_putstrn.c ./Libft/ft_strrev.c ./Libft/ft_put_hex.c ./Libft/ft_put_oct.c ./Libft/ft_unsintlen.c ./Libft/ft_putunsnbr.c ./Libft/ft_put_hexmaj.c ./Libft/ft_conv_hexmaj.c ./Libft/ft_conv_hex.c ./Libft/ft_conv_oct.c ./Libft/ft_strdup.c ./Libft/ft_strcpy.c ./Libft/ft_itoa_binary.c ./Libft/ft_atoi_binary.c 

SRC2= main.c printf.c print_argument.c  parse_flag.c auxi_parse_flag.c distribute_invalid.c distribute_pourcent.c distribute_char.c distribute_string.c distribute_int.c distribute_long.c distribute_uns.c distribute_oct.c distribute_hex.c distribute_hexmaj.c distribute_pointer.c distribute_wchar.c distribute_wstring.c auxi_rules.c auxi_rules2.c auxi_rules3.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_putnbr.c ./Libft/ft_strchrcpy.c ./Libft/ft_strcmp.c ./Libft/ft_strdel.c ./Libft/ft_strlenchr.c ./Libft/ft_strnew.c ./Libft/ft_bzero.c  ./Libft/ft_strchr.c  ./Libft/ft_strlen.c ./Libft/ft_intlen.c ./Libft/ft_memalloc.c ./Libft/ft_atoi.c ./Libft/ft_strncpy.c ./Libft/ft_putstrn.c ./Libft/ft_strrev.c ./Libft/ft_put_hex.c ./Libft/ft_put_oct.c ./Libft/ft_unsintlen.c ./Libft/ft_putunsnbr.c ./Libft/ft_put_hexmaj.c ./Libft/ft_conv_hexmaj.c ./Libft/ft_conv_hex.c ./Libft/ft_conv_oct.c ./Libft/ft_strdup.c ./Libft/ft_strcpy.c ./Libft/ft_itoa_binary.c ./Libft/ft_atoi_binary.c

OBJ= printf.o print_argument.o parse_flag.o auxi_parse_flag.o distribute_invalid.o distribute_pourcent.o distribute_char.o distribute_string.o distribute_string.o distribute_string.o distribute_int.o distribute_long.o distribute_uns.o distribute_oct.o distribute_hex.o distribute_hexmaj.o distribute_pointer.o distribute_wchar.o distribute_wstring.o auxi_rules.o auxi_rules2.o auxi_rules3.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_strchrcpy.o ft_strcmp.o ft_strdel.o ft_strlenchr.o ft_strnew.o ft_bzero.o ft_strchr.o ft_strlen.o ft_intlen.o ft_memalloc.o ft_atoi.o ft_strncpy.o ft_putstrn.o ft_strrev.o ft_put_hex.o ft_put_oct.o ft_unsintlen.o ft_putunsnbr.o ft_put_hexmaj.o ft_conv_hex.o ft_conv_hexmaj.o ft_conv_oct.o ft_strdup.o ft_strcpy.o ft_itoa_binary.o ft_atoi_binary.o

OBJ2= main.o printf.o print_argument.o parse_flag.o auxi_parse_flag.o distribute_invalid.o distribute_pourcent.o distribute_char.o distribute_string.o distribute_int.o distribute_long.o distribute_uns.o distribute_oct.o distribute_hex.o distribute_hexmaj.o distribute_pointer.o distribute_wchar.o distribute_wstring.o auxi_rules.o auxi_rules2.o auxi_rules3.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_strchrcpy.o ft_strcmp.o ft_strdel.o ft_strlenchr.o ft_strnew.o ft_bzero.o ft_strchr.o ft_strlen.o ft_intlen.o ft_memalloc.o ft_atoi.o ft_strncpy.o ft_putstrn.o ft_strrev.o ft_put_hex.o ft_put_oct.o ft_unsintlen.o ft_putunsnbr.o ft_put_hexmaj.o ft_conv_hex.o ft_conv_hexmaj.o ft_conv_oct.o ft_strdup.o ft_strcpy.o ft_itoa_binary.o ft_atoi_binary.o

HEADER= ft_printf.h
FLAGS= #-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@ $(CC) $(CFLAGS) -c $(SRC) -include $(HEADER)
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
