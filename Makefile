# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yodahani <yodahani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 10:13:51 by yodahani          #+#    #+#              #
#    Updated: 2023/02/18 16:28:48 by yodahani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Werror -Wextra
server_msg="\033[0;32m The server is ready!! \033[0m"
client_msg="\033[0;32m the Client resources is compiled \033[0m"
mini_msg="\033[0;32m You can talk to the server \033[0m"
fcleanmsg="\033[0;34m Fclean \033[0m"
cleanmsg="\033[0;34m Clean \033[0m"
bonus_msg="\033[0;32m Bonus Time \033[0m"
RM=rm -f

NAME_S= server
NAME_S_BONUS= server_bonus
NAME_C= client
NAME_C_BONUS= client_bonus

SRC_DIR= ./sources/
BONUS_DIR= ./bonus/

SRCS_S= server.c
SRCS_C= client.c
SRCSB_S= server_bonus.c
SRCSB_C= client_bonus.c

OBJS_S= $(SRCS_S:%.c=$(SRC_DIR)%.o)
OBJS_C= $(SRCS_C:%.c=$(SRC_DIR)%.o)
OBJS_S_BONUS= $(SRCSB_S:%.c=$(BONUS_DIR)%.o)
OBJS_C_BONUS= $(SRCSB_C:%.c=$(BONUS_DIR)%.o)

all:libft $(NAME_S) $(NAME_C)
	@echo $(mini_msg)

$(NAME_S):$(OBJS_S)
	@$(CC) $(CFLAGS) -Llibft -lft $(OBJS_S) -o $(NAME_S)
	@echo $(server_msg)
$(NAME_C):$(OBJS_C)
	@$(CC) $(CFLAGS) -Llibft -lft $(OBJS_C) -o $(NAME_C)
	@echo $(client_msg)

bonus:libft $(NAME_S_BONUS) $(NAME_C_BONUS)
	@echo $(bonus_msg)

$(NAME_S_BONUS): $(OBJS_S_BONUS)
	@$(CC) $(CFLAGS) -Llibft -lft $(OBJS_S_BONUS) -o $(NAME_S_BONUS)
	@echo $(server_msg)
$(NAME_C_BONUS):$(OBJS_C_BONUS)
	@$(CC) $(CFLAGS) -Llibft -lft $(OBJS_C_BONUS) -o $(NAME_C_BONUS)
	@echo $(client_msg)

libft:
	@$(MAKE) -C libft -s
clean:
	@$(MAKE) -C libft clean -s
	@$(RM) $(OBJS_C) $(OBJS_S)
	@$(RM) $(OBJS_S_BONUS) $(OBJS_C_BONUS)
	@echo $(cleanmsg)

fclean:clean
	@$(MAKE) -C libft fclean -s
	@$(RM) $(NAME_C) $(NAME_S)
	@$(RM) $(NAME_S_BONUS) $(NAME_C_BONUS)
	@echo $(fcleanmsg)

re:fclean all
rebonus: fclean bonus
.PHONY:all clean fclean re libft bonus rebonus

.SILENT:$(OBJS_C) $(OBJS_S) $(OBJS_S_BONUS) $(OBJS_C_BONUS)
	