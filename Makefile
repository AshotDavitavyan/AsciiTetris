NAME	=	game	

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -g#-fsanitize=address
LDFLAGS = -lncurses
RM		= rm -rf

OBJ_DIR	= obj
SRC_DIR = ./
SRC		= game.cpp map.cpp
OBJ		= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

HEADERS = game.hpp map.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR) 

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
