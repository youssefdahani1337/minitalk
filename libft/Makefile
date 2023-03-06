# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 16:02:51 by yodahani          #+#    #+#              #
#    Updated: 2023/02/18 14:56:07 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS =  -Wall -Wextra -Werror
libftmsg="\033[0;32m Compiling libft ... \033[0m"
SRC =	ft_atoi.c \
		ft_printf.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putbase.c \
		ft_isdigit.c

OBJ= $(SRC:.c=.o)
OBJ_bonus = $(SRC_bonus:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(libftmsg)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f ${OBJ}
	rm -f ${OBJ_bonus}
fclean: clean
	rm -f $(NAME)

re: fclean all
