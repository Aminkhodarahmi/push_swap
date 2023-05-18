# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 12:39:07 by akhodara          #+#    #+#              #
#    Updated: 2023/04/27 16:27:16 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c sorting.c firstmoves.c secondmoves.c validation.c tools.c tools2.c big_sort.c index.c

OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

MAKE = make

MOVE = mv

all: $(NAME)

	@echo ""
	@echo ""
	@echo "compiling done. Now you can sort your numbers 😜"
	@echo ""
	@echo ""
	@echo "Have Written by Amin Khodarahmi"
	@echo ""
	@echo ""
	@curl https://icanhazdadjoke.com
	@echo ""
	@echo ""


$(NAME): $(OBJS)
	@$(MAKE) -C libft/
	@$(MOVE) libft/libft.a ./
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@rm -f $(LIBFT)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean $(NAME)

.PHONY: all clean fclean re