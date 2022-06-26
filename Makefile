# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 11:06:19 by fael-bou          #+#    #+#              #
#    Updated: 2022/06/26 13:55:10 by fael-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I./inc

BUILD_DIR = build

FILES = main.o position.o sort.o mini_sort.o split.o libft.o free.o duplicate.o\
	utils/push.o utils/swap.o utils/rotate.o utils/reverse_rotate.o\
	lists/ft_lstadd_back.o lists/ft_lstclear.o \
	lists/ft_lstsize.o lists/ft_lstadd_front.o \
	lists/ft_lstlast.o lists/ft_lstnew.o

BONUS_FILES = checker_bonus.o position.o split.o libft.o free.o duplicate.o\
	utils/push_bonus.o utils/swap_bonus.o utils/rotate_bonus.o\
	utils/reverse_rotate_bonus.o\
	lists/ft_lstadd_back.o lists/ft_lstclear.o \
	lists/ft_lstsize.o lists/ft_lstadd_front.o \
	lists/ft_lstlast.o lists/ft_lstnew.o \
	gnl/get_next_line.o gnl/get_next_line_utils.o

OBG = $(addprefix $(BUILD_DIR)/, $(FILES))

BONUS_OBG = $(addprefix $(BUILD_DIR)/, $(BONUS_FILES))

NAME = push_swap

BONUS_NAME = checker

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBG)
	$(CC) $^ -o $@

$(BONUS_NAME) : $(BONUS_OBG)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean :
	rm -rf $(BUILD_DIR)

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)

re : fclean all

.PHONY : all clean fclean re
