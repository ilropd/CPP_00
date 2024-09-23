# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 12:59:23 by irozhkov          #+#    #+#              #
#    Updated: 2024/07/14 14:31:35 by irozhkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dreamjob

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
DEPS = Account.hpp

LOGF_1 = 19920104_091532.log
LOGF_2 = my_logfile.log

STRIPPEDF_1 = stripped_file1.txt
STRIPPEDF_2 = stripped_file2.txt

STRIP_TIMESTAMPS = sed 's/^\[[0-9_]*\] //'

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

$(LOGF_2):
	./$(NAME) > $@

$(STRIPPEDF_1): $(LOGF_1)
	$(STRIP_TIMESTAMPS) $< > $@

$(STRIPPEDF_2): $(LOGF_2)
	$(STRIP_TIMESTAMPS) $< > $@

compare: $(STRIPPEDF_1) $(STRIPPEDF_2)
	diff $(STRIPPEDF_1) $(STRIPPEDF_2) | wc -l

clean:
	$(REMOVE) $(shell find . -name "*.o" -o -name "*.gch")	
	@echo "---> object files $(GREEN)DELETED$(DEFAULT)\n"
	$(REMOVE) $(STRIPPEDF_1) $(STRIPPEDF_2)
	@echo "---> comparation files $(GREEN)DELETED$(DEFAULT)\n"
	$(REMOVE) $(LOGF_1) $(LOGF_2)
	@echo "---> log files $(GREEN)DELETED$(DEFAULT)\n"

fclean: clean
	$(REMOVE) $(NAME)
	@echo "---> $(NAME) $(GREEN)DELETED$(DEFAULT)\n"

re: fclean all

.PHONY: all compare clean fclean re
