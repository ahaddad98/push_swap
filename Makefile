# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 13:45:54 by ahaddad           #+#    #+#              #
#    Updated: 2021/04/17 15:29:09 by ahaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= checker
NAME1= push_swap
SRC_PATH1= ./push_swap_program/sources
SRC_PATH= ./Checker_program/srcs
HDR_PATH= includes
OBJ_PATH= ./Checker_program/obj
OBJ_PATH1= ./push_swap_program/obj
LIB_PATH= libft

SRC_NAME=swap.c\
		main.c\
		push.c\
		rotate.c\
		get_next_line.c\
		get_next_line_utils.c\
		push_b.c\
		main_tools.c\

SRC_NAME1=main.c\
		push.c\
		push_b.c\
		swap.c\
		rotate.c\
		tools.c\
		tri_insert.c\
		get_param.c\
		algo_three.c\
		get_use_med.c\
		tools2.c\
		algo_five.c\
		

HDR_NAME=push_swap.h

OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ_NAME1= $(SRC_NAME1:.c=.o)

OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

OBJ1= $(addprefix $(OBJ_PATH1)/,$(OBJ_NAME1))
SRC1= $(addprefix $(SRC_PATH1)/,$(SRC_NAME1))
HDR1= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB= libft.a
# FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_FLAG= -I $(HDR_PATH)

COMP= gcc

all: lib  $(NAME) $(NAME1)

$(NAME) : $(LIB_PATH)/$(LIB) $(OBJ)
		@rm -rf $(NAME)
		@$(COMP) -g $(H_FLAG) $(OBJ) $(LLIB_FLAG) -o $@
$(NAME1) : $(LIB_PATH)/$(LIB) $(OBJ1)
		@rm -rf $(NAME1)
		@$(COMP) -g $(H_FLAG) $(OBJ1) $(LLIB_FLAG) -o $@
		@echo " Made by : \033[1;91mAhaddad\033[m"

lib:
		@make -sC $(LIB_PATH)

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
			@mkdir -p $(OBJ_PATH) 
			@$(COMP) -g $(FLAGS) $(H_FLAG) -g -o $@ -c $<
$(OBJ_PATH1)/%.o:  $(SRC_PATH1)/%.c $(HDR)
			@mkdir -p $(OBJ_PATH1) 
			@$(COMP) -g $(FLAGS) $(H_FLAG) -g -o $@ -c $<

clean:
		@rm -rf $(OBJ_PATH)
		@rm -rf $(OBJ_PATH1)
		@make clean -C $(LIB_PATH)

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C $(LIB_PATH)
		@rm -rf $(NAME1)
		@echo "all objects are deleted."  

re : fclean all
