
# Output name
NAME = pipex

# Compilation
CC = cc
FLAGS = -Wall -Wextra -Werror

# Paths
SRC_DIR = ./src
INCLUDES = ./includes
LIBFTi_DIR= ./libft

# Objects
OBJS = $(SRC_DIR:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(SRC_DIR) -I $(LIBFT) $ -c $< -o $@

clean: 
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -c $(LIBFT_DIR)

re: fclean
	make all

.PHONY: all clean fclean re bonus
