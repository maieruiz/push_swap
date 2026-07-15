NAME = push_swap

MAKEFLAGS = -silent
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = push_swap.c rot_reverse.c rotate.c \
		swap.c check_args.c correct_stack.c \
		benchmark.c disorder_checker.c node_stack.c program.c \
		push_swap.c simple_algorithm.c utilities.c call_algorithm.c\
		index.c medium_algorithm.c chunk.c adaptive_algorithm.c\
		complex_algorithm.c

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

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
