# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: livliege <livliege@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/27 18:35:15 by livliege      #+#    #+#                  #
#    Updated: 2025/04/01 15:30:22 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	:= megaphone

CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address 

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
