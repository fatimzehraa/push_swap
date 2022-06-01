# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fatimzehra </var/spool/mail/fatimzehra>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 11:06:19 by fatimzehra        #+#    #+#              #
#    Updated: 2022/05/31 11:53:00 by fatimzehra       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

BUILD_DIR = build

FILES = main.o

OBG = $(addprefix $(BUILD_DIR)/, $(FILES))

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -rf $(BUILD_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean
