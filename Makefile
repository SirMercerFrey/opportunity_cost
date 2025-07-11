# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcharret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 16:27:50 by mcharret          #+#    #+#              #
#    Updated: 2025/07/11 18:17:22 by mcharret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinclude

SRC_DIR	= src
OBJ_DIR	= obj

SRC		= \
		src/main.c \
		src/core.c \
		src/analysis_a.c \
		src/analysis_b.c \
		src/cases.c \
		src/cases_bis.c \
		src/instructions.c \
		src/quick_sort.c \
		src/utils.c \
		src/utils_bis.c \
		src/utils_ter.c \
		src/instructions_bis.c \
		src/utils_quater.c 

OBJ		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
