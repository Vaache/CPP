NAME	= megaphone

SRC = ./megaphone.cpp

OBJ	= $(SRC:.cpp=.o)

CC		= c++
CFLAGS	= -Wall -Wextra -Werror
MK		= mkdir -p

all: $(NAME)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re