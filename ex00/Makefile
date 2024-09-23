# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 17:03:38 by irozhkov          #+#    #+#              #
#    Updated: 2024/06/28 17:24:53 by irozhkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = megaphone.o

REMOVE = rm -f

GREEN = \033[0;32m
DEFAULT = \033[0m

all: $(NAME)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "---> object files $(GREEN)CREATED$(DEFAULT)\n"
	$(CC) $(OBJ) -o $(NAME)
	@echo "---> $(NAME) is $(GREEN)AVAILABLE NOW$(DEFAULT)\n"

clean:
	$(REMOVE) $(shell find . -name "*.o")
	@echo "---> object files $(GREEN)DELETED$(DEFAULT)\n"

fclean: clean
	$(REMOVE) $(NAME)
	@echo "---> $(NAME) $(GREEN)DELETED$(DEFAULT)\n"

re: fclean all

.PHONY: all clean fclean re
