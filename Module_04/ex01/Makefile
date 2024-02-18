NAME	= Brain

SRC 	= $(wildcard *.cpp)

OBJ		= $(patsubst %.cpp, %.o, $(SRC))


CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 $(INCLUDES)
HEADERS 	= $(wildcard *.hpp)
INCLUDES	= -I./
MK			= mkdir -p

# test :
# 	@echo $(HEADERS)

all: $(NAME)


%.o: %.cpp $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re