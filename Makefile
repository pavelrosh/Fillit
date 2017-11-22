# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsheptun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 10:57:47 by dsheptun          #+#    #+#              #
#    Updated: 2017/11/22 10:57:49 by dsheptun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJECTS =
SRCS = 

.SILENT:

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -c -I $(SRCS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
all: $(NAME)
.PHONY: clean fclean re all
