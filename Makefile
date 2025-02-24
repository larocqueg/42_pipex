# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 15:21:10 by gde-la-r          #+#    #+#              #
#    Updated: 2025/02/14 15:21:12 by gde-la-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output name
NAME = pipex
NAME_BONUS = pipex_bonus

# Compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Paths
SRC_DIR = ./src
BONUS_DIR = ./bonus
INCLUDES = ./includes
LIBFT_DIR = ./libft

# Sources
SRC = $(SRC_DIR)/main.c \
	  $(SRC_DIR)/utils.c \
	  $(SRC_DIR)/error.c \

BONUS = $(BONUS_DIR)/main_bonus.c \
		$(BONUS_DIR)/utils_bonus.c \

# Objects
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_DIR) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_DIR) -c $< -o $@

clean: 
	rm -rf $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	rm -rf outfile infile
	make fclean -C $(LIBFT_DIR)

re: fclean
	make all

.PHONY: all clean fclean re
