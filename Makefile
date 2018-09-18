# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msefako <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 14:56:42 by msefako           #+#    #+#              #
#    Updated: 2018/08/28 16:12:28 by msefako          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
SRC =	src/checker.c \
		src/check_errors.c \
		src/rotate_push.c \
		src/rr.c \
		src/swap.c 

INCLUDES = libft/libft.a

$(NAME):
	@make -C libft
	@gcc -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME)
	@echo "$(NAME) created Successfully!"

all: $(NAME)

clean:
	@make -C libft clean
	@echo "rule 'clean' finished successfully"

fclean: clean
	@rm -rf libft/$(NAME)
	@rm -f $(NAME)
	@echo "rule 'fclean' finished successfully"

re: fclean all
