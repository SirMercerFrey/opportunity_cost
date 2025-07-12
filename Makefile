# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcharret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 16:27:50 by mcharret          #+#    #+#              #
#    Updated: 2025/07/12 18:14:37 by mcharret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude

SRC_DIR		= src
OBJ_DIR		= obj
BONUS_DIR	= bonus

SRC			= \
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

BONUS_SRC	= \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \
			bonus/instructions.c \
			bonus/instructions_bis.c \
			bonus/utils.c \
			bonus/utils_bis.c \
			bonus/utils_ter.c \
			bonus/utils_quater.c \
			bonus/checking.c \
			bonus/main.c 

OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ	= $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus 
