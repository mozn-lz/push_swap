# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozn <mozn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 14:56:42 by msefako           #+#    #+#              #
#    Updated: 2019/08/29 22:05:30 by mozn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

C_SRC =	src/checker.c	src/check_errors.c src/rotate_push.c src/rr.c src/swap.c
P_SRC =	src/push_swap.c src/check_errors.c src/rotate_push.c src/rr.c src/swap.c src/algos.c

INCLUDES = libft/libft.a

$(NAME):
	@make -C libft
	@gcc -Wall -Werror -Wextra $(C_SRC) $(INCLUDES) -o $(NAME)
	@echo "$(NAME) created Successfully!"
$(NAME2):
	@make -C libft
	@gcc -Wall -Werror -Wextra $(P_SRC) $(INCLUDES) -o $(NAME2)
	@echo "$(NAME2) created Successfully!"

all: $(NAME) $(NAME2)

clean:
	@make -C libft clean
	@echo "rule 'clean' finished successfully"

fclean: clean
	@rm -rf libft/$(NAME)
	@rm -f $(NAME)
	@rm -rf libft/$(NAME2)
	@rm -f $(NAME2)
	@echo "rule 'fclean' finished successfully"

re: fclean all
