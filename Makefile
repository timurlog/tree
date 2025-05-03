# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 14:44:56 by tilogie           #+#    #+#              #
#    Updated: 2025/05/03 14:50:24 by tilogie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

PROG		= tree
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -I $(INCLUDE)
RM			= rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	tree


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(PROG)

$(PROG):	$(OBJ)
			@$(CC) $(OBJ) -o $(PROG)
			@echo "$(GREEN)tree compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)tree object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(PROG)
			@echo "$(CYAN)tree executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for tree!$(DEF_COLOR)"

norm:
			@norminette include | grep -v OK! -B1 || true
			@norminette src | grep -v OK! -B1 || true

.PHONY:		all clean fclean re norm
