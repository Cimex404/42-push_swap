# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 08:46:24 by jgraf             #+#    #+#              #
#    Updated: 2025/02/03 08:46:32 by jgraf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS= -Wall -Wextra -Werror -Iinclude
NAME = push_swap
CHECKER = checker

#			SOURCE FILES
SRC_UTILS = $(addprefix utils/, ft_printf.c input_handle.c free_memory.c check_sorted.c check_double.c get_highlow.c min.c)
SRC_ALGTHM = $(addprefix algorithm/, simple_sort.c three_sort.c double_sort.c double_sort_utils.c double_sort_back.c)
SRC_OP = $(addprefix operations/, push_command.c swap_command.c rotate_command.c rev_rotate_command.c)
SRC_LIBFT = $(addprefix libft/, ft_strlen.c ft_split.c ft_atoi.c)
SRC_CHECK = $(addprefix checker/, checker.c get_next_line.c get_next_line_utils.c)

SRC = $(addprefix src/, main.c $(SRC_UTILS) $(SRC_ALGTHM) $(SRC_OP) $(SRC_LIBFT))
CHECK_SRC = $(addprefix src/, $(SRC_CHECK) $(SRC_OP) $(SRC_UTILS) $(SRC_LIBFT))

#			OBJECT FILES
OBJ = $(SRC:.c=.o)
CHECK_OBJ = $(CHECK_SRC:.c=.o)

#			COMPILATION RULES
all: $(NAME) bonus

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(CHECK_OBJ)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECK_OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f $(OBJ) $(CHECK_OBJ)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
