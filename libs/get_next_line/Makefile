# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 14:48:58 by ahooghe           #+#    #+#              #
#    Updated: 2023/12/05 14:58:42 by ahooghe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=gnl.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
AR=ar -rcs
SRCS=get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS=$(SRCS:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all