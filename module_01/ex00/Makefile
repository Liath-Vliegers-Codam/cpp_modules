# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: livliege <livliege@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/27 18:35:15 by livliege      #+#    #+#                  #
#    Updated: 2025/03/27 21:34:50 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME	:= phonebook

CC		:= g++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror 
#-g -fsanitize=address

SRC		:= phonebook.cpp

OBJ		:= $(SRC:.cpp=.o)

all: $(NAME)

run: all
	./$(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: 
	@$(RM) $(NAME) $(OBJ)

re: fclean all

.PHONY: clean all fclean re
