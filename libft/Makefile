# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:01:56 by lcharvol          #+#    #+#              #
#    Updated: 2016/11/11 18:29:40 by lcharvol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	  ft_putchar.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_strcpy.c \
	  ft_strlen.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcmp.c \
	  ft_isalnum.c \
	  ft_isdigit.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_isalnum.c \
	  ft_atoi.c \
	  ft_strstr.c \
	  ft_strncmp.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strnstr.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strdel.c \
	  ft_strnew.c \
	  ft_memdel.c \
	  ft_memalloc.c \
	  ft_memset.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strdup.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_memcmp.c \
	  ft_memchr.c \
	  ft_memmove.c \
	  ft_itoa.c \
	  ft_strlcat.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  get_next_line.c \

O = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Wall

HEADER = includes
INC_D = $(shell find . | grep "\.h") 

all: $(NAME) $(O) $(INC_D)

$(NAME): $(O) 
	gcc $(FLAG) -c $(SRC) -I$(HEADER) && ar rc $(NAME) $(O)

clean:
	/bin/rm -f $(O)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(O)

re: fclean all
