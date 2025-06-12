# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: livliege <livliege@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/27 18:35:15 by livliege      #+#    #+#                  #
#    Updated: 2025/06/12 10:07:27 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		:= zombies_ex00

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address 

OBJ_DIR		:= obj
SRC_DIR		:= src

INCL		:= Zombie.hpp

SRCS		:= 	main.cpp \
				newZombie.cpp \
				randomChump.cpp \
				Zombie.cpp

# Convert source files into object files
OBJS		:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Default rule (compiles the program)
all: $(NAME)

# Linking the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I . $^ -o $@

# Compiling source files into object files
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I . -c $< -o $@

# Ensure the object directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Cleaning compiled files
clean:
	rm -rf $(OBJ_DIR)

# Cleaning everything (object files + executable)
fclean: clean
	rm -rf $(NAME)

# Recompile everything
re: fclean all

# Compile and run the program
run: all
	./$(NAME)

# Phony targets (to prevent conflicts with actual files)
.PHONY: all clean fclean re run
