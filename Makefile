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

SRC = src/*.c libft/libft.a

OBJ = *.c

FLAGS = -Wall -Wextra -Werror

HEADER = headers.h

all: $(NAME)

$(NAME):
	gcc $(SRC) $(HEADER)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: $(NAME)
	./a.out
