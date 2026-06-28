NAME = push_swap

MAKEFLAGS = -silent
CFLAGS = -Wall -Werror -Wextra

FILES = main.c operations.c check_args.c push_swap.c

OBJ = $(FILES:.c=.o)

$(NAME): $(OBJ)
	cc $(FLAGS) $(SRCS) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all = $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
