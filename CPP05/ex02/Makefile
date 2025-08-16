CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98

DEFAULT := \033[0m
MAGENTA := \033[35m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
RED := \033[31m

NAME := EX02
SRCS := main.cpp Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp
 
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@printf "$(MAGENTA)[$(NAME)] $(DEFAULT)Compiling ($(BLUE)$(NAME)$(DEFAULT))...\n"
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
	@printf "$(MAGENTA)[$(NAME)] $(GREEN)Compilation successful 🎉!$(DEFAULT)\n"

clean:
	@printf "$(MAGENTA)[$(NAME)] $(DEFAULT)Cleaning up ($(RED)$(NAME)$(DEFAULT))...\n"
	@$(RM) $(NAME)
	@printf "$(MAGENTA)[$(NAME)] $(YELLOW)Clean successful 🧹$(DEFAULT)\n"

fclean: clean
	@printf "$(MAGENTA)[$(NAME)] $(YELLOW)Full clean successful 🧹🧹$(DEFAULT)\n"

re: fclean all

.PHONY: all clean fclean re

