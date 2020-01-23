# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayellin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 14:21:49 by ayellin           #+#    #+#              #
#    Updated: 2020/01/22 20:45:42 by ayellin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

LIBFT_DIR = libft

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -O3

SRC = bit_util.c            \
      color_util.c          \
      flags_parser.c        \
      float_util.c          \
      ft_ldtoa.c            \
      ft_printf.c           \
      ft_putwchar.c         \
      get_digit.c           \
      get_f.c               \
      get_float.c           \
      get_float_part.c      \
      get_hex.c             \
      get_int_part.c        \
      get_oct.c             \
      get_p.c               \
      get_sd.c              \
      get_ud.c              \
      long_arithmetic.c     \
      precision_parser.c    \
      prepare_f_buf.c       \
      print_basic.c         \
      print_char.c          \
      print_d_buf.c         \
      print_digit_buf.c     \
      print_e_buf.c         \
      print_f_buf.c         \
      print_float.c         \
      print_hex.c           \
      print_hex_buf.c       \
      print_oct.c           \
      print_oct_buf.c       \
      print_other.c         \
      print_sd_buf.c        \
      print_str.c           \
      print_ud.c            \
      print_util.c          \
      print_ws.c            \
      printf_constants.c    \
      put_buffered_char.c   \
      round_float.c         \
      size_parser.c         \
      spec_format_parser.c  \
      spec_util.c           \
      special_float_values.c \
      specificator.c        \
      type_func_table.c     \
      type_parser.c         \
      util.c                \
      width_parser.c        \

LIBFT_SRC =  libft/ft_strdup.c libft/ft_memset.c libft/ft_strchri.c libft/ft_convert/ft_itoa_base.c libft/ft_convert/ft_lltoa_base.c libft/ft_convert/ft_ulltoa_base.c libft/ft_atoi.c libft/ft_exit.c libft/ft_bzero.c libft/ft_isdigit.c libft/ft_power.c libft/ft_memalloc.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_str_func_not_find.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strcmp.c libft/ft_strcspn.c libft/ft_strlen.c libft/ft_strrev.c libft/ft_strsub.c libft/ft_isspace.c libft/ft_memcmp.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strcpy.c libft/ft_strnew.c libft/ft_strncpy.c libft/ft_convert/ft_uitoa_base.c

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
