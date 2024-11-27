CC = g++
NAME = FragTrap

CFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3 -pedantic

SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re