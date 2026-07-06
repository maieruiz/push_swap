NAME = push_swap

MAKEFLAGS = -silent
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = main.c\ 
		operations.c\ 
		check_args.c\ 
		push_swap.c\
		disorder_checker.c\
		node_stack.c\
		simple_algorithm.c\
		medium_algorithm.c\
		complex_algorithm.c\
		adaptative_algorithm.c\
		nosedondemeterlo.c\
		benchmark.c\
		program.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	cc $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
