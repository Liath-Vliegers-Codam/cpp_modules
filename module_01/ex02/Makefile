# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: livliege <livliege@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/27 18:35:15 by livliege      #+#    #+#                  #
#    Updated: 2025/03/31 16:33:34 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                Makefile                                     #
# **************************************************************************** #
NAME		:= hi_im_brain

CC			:= g++
CFLAGS		:= -Wall -Wextra -Werror -g -fsanitize=address

OBJ_DIR		:= obj
SRC_DIR		:= src  # Define a source directory for better organization

# List of source files
SRCS		:= 	main.cpp

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
