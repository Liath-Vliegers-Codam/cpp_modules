# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: livliege <livliege@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/02/27 18:34:37 by livliege      #+#    #+#                  #
#    Updated: 2025/03/27 18:34:37 by livliege      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	:= megaphone

CC		:= g++
FLAGS	:= -Wall -Wextra -std=c++98

SRC		:= megaphone.cpp

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
