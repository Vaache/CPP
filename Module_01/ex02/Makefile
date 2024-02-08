NAME	= main

SRC 	= $(wildcard *.cpp)


OBJ		= $(patsubst %.cpp, %.o, $(SRC))


CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all: $(NAME)


$(OBJ)/%.o: $(SRC)/%.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re