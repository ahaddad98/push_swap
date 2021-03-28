# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amine <amine@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 13:45:54 by ahaddad           #+#    #+#              #
#    Updated: 2021/03/28 14:37:27 by amine            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SRC_PATH= srcs
HDR_PATH= includes
OBJ_PATH= obj
LIB_PATH= libft

SRC_NAME=sa.c\
		main.c\
		push.c\

HDR_NAME=push_swap.h

OBJ_NAME= $(SRC_NAME:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB= libft.a
# FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_FLAG= -I $(HDR_PATH)

COMP= gcc

all: lib  $(NAME)

$(NAME) : $(LIB_PATH)/$(LIB) $(OBJ)
		@rm -rf push_swap
		@$(COMP) -g $(H_FLAG) $(OBJ) $(LLIB_FLAG) -o $@
		@echo " Made by : \033[1;91mAhaddad\033[m"

lib:
		@make -sC $(LIB_PATH)

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
			@mkdir -p $(OBJ_PATH) 
			@$(COMP) -g $(FLAGS) $(H_FLAG) -g -o $@ -c $<

clean:
		@rm -rf $(OBJ_PATH)
		@make clean -C $(LIB_PATH)

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C $(LIB_PATH)
		@echo "all objects are deleted." 

re : fclean all