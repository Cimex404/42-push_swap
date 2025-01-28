C = cc
CFLAGS= -Wall -Wextra -Werror -Iinclude
NAME = push_swap
LIBFT = libft/libft.a
SRC = src/main.c src/utils/ft_printf.c \
	src/utils/input_handle.c src/utils/free_memory.c src/utils/check_sorted.c \
	src/utils/check_double.c src/utils/get_highlow.c src/utils/min.c \
	src/algorithm/simple_sort.c src/algorithm/three_sort.c src/algorithm/double_sort.c \
	src/algorithm/double_sort_utils.c src/algorithm/double_sort_back.c \
	src/operations/push_command.c src/operations/swap_command.c src/operations/rotate_command.c \
	src/operations/rev_rotate_command.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f $(OBJ)
	make fclean -C libft

fclean: clean
	rm -f $(NAME)
	make clean -C libft

re: fclean all

.PHONY: all clean fclean re
