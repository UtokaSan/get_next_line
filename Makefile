# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 01:51:20 by fboulbes          #+#    #+#              #
#    Updated: 2024/11/22 00:53:57 by fboulbes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(SIZE)
NAME = my_gnl
SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)
HEADER = get_next_line.h
SIZE = 50

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -g $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)