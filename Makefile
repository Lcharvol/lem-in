# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 00:39:19 by lcharvol          #+#    #+#              #
#    Updated: 2017/03/04 00:39:21 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS = 	main.c \
		tools.c \
		parcing.c \
		ft_op_room.c \
		ft_op_tube.c  \
		ft_solve.c \
		ft_op_path.c \
		ft_solve2.c \
		ft_verif.c \

INC = ./includes/lemin.h

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(addprefix srcs/, $(SRCS:.c=.o))

all: libft $(NAME) 

libft:
	@make -C libft

$(NAME): libft $(INC) $(OBJ) 
	@make -C libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) -L libft -lft

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
