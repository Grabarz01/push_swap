CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
C_FILES = comands_00.c comands_01.c comands_exe.c cost_cal.c find_in_stack.c free_fun.c \
		input_checkers.c main.c sorting.c stack_builders.c stack_checkers.c stack_management.c
O_FILES = $(C_FILES:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
RM = rm -rf

all: $(NAME)

$(NAME): $(O_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -c 	$< -o $@

clean:
	$(RM) $(O_FILES)
	make -C $(LIBFT_PATH) clean 

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) clean 

re: fclean all

.PHONY: all clean fclean re