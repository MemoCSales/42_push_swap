NAME 	= push_swap
LIBFT 	= ./libft/libft.a
HEADER 	= header/
SRC_DIR = src/
OBJ_DIR = obj/
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror

SRC = 	$(SRC_DIR)push_swap/main.c \
		$(SRC_DIR)push_swap/stack_init.c \
		$(SRC_DIR)push_swap/error_handling.c  \
		$(SRC_DIR)push_swap/stack_utils.c \
		$(SRC_DIR)push_swap/deallocation.c \
		$(SRC_DIR)push_swap/indexing.c \
		$(SRC_DIR)push_swap/init_a_to_b.c \
		$(SRC_DIR)push_swap/node_init.c \
		$(SRC_DIR)rules/swap.c \
		$(SRC_DIR)rules/sort_three.c \
		$(SRC_DIR)rules/push.c \
		$(SRC_DIR)rules/rotate.c \
		$(SRC_DIR)rules/rrotate.c \

all: $(NAME)

# OBJ = $(SRC:.c=.o)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

INCLUDE = -L ./libft -lft -I ./header

$(LIBFT):
		make -C ./libft

$(NAME): $(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT)  -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
clean:
	rm -rf $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@rm  -f ./$(NAME)
	@rm -f ./$(LIBFT)

re: fclean all

.PHONY: all clean fclean re