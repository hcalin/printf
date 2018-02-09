# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 15:07:35 by chrihorc          #+#    #+#              #
#    Updated: 2017/05/04 15:07:53 by chrihorc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INCLUDE = printf.h libft.h
FILES = ft_printf.c ft_putstr.c ft_strlen.c ft_atoi.c ft_strchr.c ft_putnbr.c \
	ft_nbrlen.c ft_putchar.c ft_putnstr.c ft_strncpy.c handle_arg.c \
	handle_dsc.c handle_format.c handle_format_2.c handle_hexa.c \
	handle_int.c handle_octa.c handle_ptr.c handle_unsg.c \
	helper_func_2.c helper_func.c ft_isdigit.c handle_hexa_2.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) -c $(FILES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[0;32m[PRINTF COMPILED]"

clean :
	@echo "\033[0;32m[CLEANING OBJECT FILES]"
	@rm -f $(OBJ)
fclean : clean
	@echo "\033[0;32m[CLEANING $(NAME)]"
	@rm -f $(NAME)

re : fclean all
