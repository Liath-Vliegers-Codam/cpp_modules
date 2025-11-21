
NAME		:= module_05

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++11 #-g -fsanitize=address 

OBJ_DIR		:= obj
SRC_DIR		:= src

INCL		:=	AForm.hpp \
				Bureaucrat.hpp \
				PresidentialPardonForm.hpp \
				RobotomyRequestForm.hpp \
				ShrubberyCreationForm.hpp \
				Intern.hpp #DELETE IN EX02!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				
SRCS		:= 	AForm.cpp \
				Bureaucrat.cpp \
				PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp \
				ShrubberyCreationForm.cpp \
				ex03_main.cpp \
				Intern.cpp #DELETE IN EX02!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
