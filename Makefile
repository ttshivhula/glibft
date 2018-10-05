# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 12:28:51 by ttshivhu          #+#    #+#              #
#    Updated: 2018/10/05 09:39:06 by ttshivhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftg.a

SRCS = garbage.c utils.c gstrdup.c \

FLAG = -Wall -Werror -Wextra -I.

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
