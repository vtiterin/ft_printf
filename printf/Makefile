# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtiterin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 12:22:29 by vtiterin          #+#    #+#              #
#    Updated: 2016/12/02 12:22:31 by vtiterin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
GCC		= gcc
WWW		= -Wall -Wextra -Werror
SRC		= ft_char.c ft_decimal.c ft_fdec.c ft_fdec1.c ft_fhex.c \
			ft_fhexx.c ft_foct.c ft_foption1.c ft_fpoint.c ft_fstr.c \
			ft_fudecimal1.c ft_func.c ft_func1.c ft_fwstr.c \
			ft_hexad.c ft_hexadx.c ft_octal.c ft_options.c \
			ft_percent.c ft_point.c ft_pr_wrong.c ft_printf.c \
			ft_pwt.c ft_solv.c ft_str_s.c ft_udecimal.c ft_wtstr.c \
			ft_wchlen.c ft_foct1.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		mv libft/libft.a ./$(NAME)
		$(GCC) -c $(FLAG) $(SRC) -I ./
		ar rv $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		make clean -C libft/
		rm -rf $(OBJ)

fclean : clean
		make fclean -C libft/
		rm -rf $(NAME)

re : 	fclean all
