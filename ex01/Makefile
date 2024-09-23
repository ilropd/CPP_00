# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 18:37:40 by irozhkov          #+#    #+#              #
#    Updated: 2024/07/12 19:01:46 by irozhkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp main.cpp message.cpp PhoneBook.cpp utils.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = colors.hpp Contact.hpp message.hpp PhoneBook.hpp utils.hpp

REMOVE = rm -f

GREEN = \033[0;32m
DEFAULT = \033[0m

all: $(NAME)

%.o: %.cpp $(DEPS) Makefile
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

