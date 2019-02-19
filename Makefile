# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/28 15:19:07 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2019/02/19 20:41:45 by shthevak    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = ft_select

# **************************************************************************** #
#									PATH                                       #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

# **************************************************************************** #
# 									SRCS                                       #
# **************************************************************************** #

INC_NAME =ft_select.h

SRC_NAME = main.c str.c select_str.c tab.c free_str.c struct.c free_struct.c

# **************************************************************************** #
#  									VAR                                        #
# **************************************************************************** #

OBJ_NAME = $(SRC_NAME:.c=.o)
INC = $(addprefix $(INC_PATH), $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

# **************************************************************************** #
#  									FLAG                                       #
# **************************************************************************** #

ifndef FLAG
	FLAG = -Wall -Werror -Wexta -fsanitize=address -lcurses
endif

NORME = norminette

# **************************************************************************** #
#  									STYLE                                      #
# **************************************************************************** #

SAY=@echo
SAYD=@echo $

R_1= \033[1A
CLEAR_R= \033[J
WHITE= "\033[1;37m
GREEN= "\033[1;32m
RED= "\033[1;31m
YELLOW= "\033[1;33m
BLUE= "\033[1;34m
END= \033[0m"

# **************************************************************************** #
# 									REGLES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	$(SAY) "$(R_1) $(CLEAR_R)\n$(END)
	@gcc -o $@ $(OBJ) $(FLAG)
	$(SAY) $(GREEN) $(R_1) $(CLEAR_R) 	                                   ☑️  ft_select ☑️ \n$(END)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  	                          Directory ./obj created$(END)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<
	$(SAY) $(YELLOW) $(R_1) $(CLEAR_R)  		              Binary File done : $*$(END)

clean:
	$(SAY) "$(R_1) $(CLEAR_R)\n$(END)
	@rm -rf $(OBJ_PATH) 2> /dev/null
	$(SAY) $(RED) $(R_1) $(CLEAR_R) 	             🗑️ Minishell : Binary files directory \"/obj\" hab been deleted.🗑️\n$(END)

fclean: clean
	@rm -rf $(NAME) 2> /dev/null
	$(SAY) $(RED) $(R_1) $(CLEAR_R)     	                             ❌ ft_select has been deleted.❌ \n$(END)

new_line:
	$(SAY)

re: fclean new_line  all
