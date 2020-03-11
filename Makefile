# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epalomak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 13:09:45 by epalomak          #+#    #+#              #
#    Updated: 2020/01/08 13:14:31 by epalomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./src/ft_printf.c ./src/checks.c ./src/ft_itoa_base.c ./src/helper.c \
	./src/print_c.c ./src/print_d.c ./src/print_f.c ./src/print_o.c \
	./src/print_p.c ./src/print_s.c ./src/print_u.c ./src/print_x.c \
	./src/print_special.c ./src/ft_intmax_toa.c ./src/ft_uintmax_toa.c \
	./src/ft_ftoa.c

OBJ = ft_printf.o checks.o ft_itoa_base.o helper.o print_c.o print_d.o \
print_f.o print_o.o print_p.o print_s.o print_u.o print_x.o print_special.o \
ft_intmax_toa.o ft_uintmax_toa.o ft_ftoa.o


FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

INC = headers.h

all: $(NAME)

$(NAME):
	@make -C libft
	@cp $(LIBFT) $(NAME)
	@gcc -c $(FLAGS) $(SRC) $(INC)
	@ar rc $(NAME) $(OBJ)

clean:
	@make -C libft clean
	@/bin/rm -f *.o

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

run: re
	@gcc libftprintf.a main.c
	@./a.out