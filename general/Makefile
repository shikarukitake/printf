# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayellin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:21:49 by ayellin           #+#    #+#              #
#    Updated: 2020/01/19 04:14:24 by ayellin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

LIBFT_DIR = libft

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = print_d_buf.c print_digit_buf.c print_oct_buf.c print_str.c print_ws.c color_util.c print_hex_buf.c print_other.c ft_putwchar.c type_parser.c print_char.c print_basic.c ft_printf.c get_sd.c print_ud.c util.c print_buffer.c get_digit.c get_ud.c size_parser.c width_parser.c flags_parser.c get_f.c           spec_format_parser.c float_convert.c get_float.c precision_parser.c specificator.c float_print.c get_hex.c print_hex.c ft_float.c get_oct.c print_oct.c type_func_table.c bit_util.c get_p.c printf_constants.c

LIBFT_SRC =  libft/ft_memset.c libft/ft_strchri.c libft/ft_convert/ft_itoa_base.c libft/ft_convert/ft_lltoa_base.c libft/ft_convert/ft_ulltoa_base.c libft/ft_atoi.c libft/ft_exit.c libft/ft_bzero.c libft/ft_isdigit.c libft/ft_power.c libft/ft_memalloc.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_str_func_not_find.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strcmp.c libft/ft_strcspn.c libft/ft_strlen.c libft/ft_strrev.c libft/ft_strsub.c libft/ft_isspace.c libft/ft_memcmp.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strcpy.c libft/ft_strnew.c libft/ft_strncpy.c libft/ft_convert/ft_uitoa_base.c

SRCS = $(addprefix srcs/, $(SRC)) $(LIBFT_SRC)

OBJ = $(SRCS:.c=.o)

LIBFT_INC = ./libft/includes/

INC = ./includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	    $(CC) $(CFLAGS) -I$(LIBFT_INC) -I$(INC) -c -o $@ $<
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
