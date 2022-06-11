# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 11:06:19 by fael-bou          #+#    #+#              #
#    Updated: 2022/06/10 20:07:23 by fatimzehra       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I./inc

BUILD_DIR = build

FILES = main.o position.o sort.o\
	utils/push.o utils/swap.o utils/rotate.o utils/reverse_rotate.o\
	lists/ft_lstadd_back.o lists/ft_lstclear.o \
	lists/ft_lstsize.o lists/ft_lstadd_front.o \
	lists/ft_lstdelone.o lists/ft_lstlast.o lists/ft_lstnew.o

OBG = $(addprefix $(BUILD_DIR)/, $(FILES))

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean :
	rm -rf $(BUILD_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
