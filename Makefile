# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/26 16:37:37 by grass-kw          #+#    #+#              #
#    Updated: 2016/07/23 16:15:27 by grass-kw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




CC=gcc
CFLAGS=-Wall -Werror -Wextra -I./includes
NAME= libclst.a
FILES= clst_new.c clst_iter.c clst_push_front.c clst_push_back.c \
		clst_last_link.c clst_map.c clst_delone.c clst_first_link.c \

OBJ=$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
