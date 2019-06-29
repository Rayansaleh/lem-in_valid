# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlaine <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 16:21:32 by arlaine           #+#    #+#              #
#    Updated: 2019/04/23 17:03:30 by rsaleh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

COMP_FLAGS = gcc -Wall -Wextra -Werror
COMP = gcc

P_SRCS = srcs/*.c
P_LIBFT = libft/
LIB_NAME = libft.a

INCLUDE = includes/lemin.h
LIBFT_INCLUDE = libft/libft.h

LIBFT_OBJS = $(addprefix $(P_LIBFT), $(.c=.o))

#COLORS#
BLACK = \033[30
BLACK2 = \033[40
RED = \033[31
RED2 = \033[41
GREEN = \033[32
GREEN2 = \033[42
YELLOW = \033[33
YELLOW2 = \033[43
BLUE = \033[34
BLUE2 = \033[44
MAGENTA = \033[35
MAGENTA2 = \033[45
CYAN = \033[36
CYAN2 = \033[46
GREY = \033[37
GREY2 = \033[47
COLOR_RESET = \033[0

#FORMATING_TEXT#
DEFAULT = ;0
GRAS = ;1
SOULIGNER = ;4
CLIGNOTANT = ;5
SURLIGNER = ;7

all: lib $(NAME)

#.SILENT:
$(NAME):
	@$(COMP_FLAGS) $(P_SRCS) -I $(INCLUDE) $(addprefix $(P_LIBFT), $(LIB_NAME)) \
		-o $(NAME)
	@echo "$(GREEN)$(GRAS)m➜ lem-in created " '✅' '.'

lib:
	@make -C $(P_LIBFT)
	@echo "$(GREEN)$(GRAS)m➜ Lib compiled "'✅' '.'

clean:
	@make clean -C $(P_LIBFT)
	@rm -rf $(P_OBJ)
	@echo "$(GREEN)$(GRAS)m➜ Cleaning objects files and libft.a" '♻️' '.'
	@echo "$(GREEN)$(GRAS)m➜ Objects files and libft.a cleaned" '✅' '.'

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(P_LIBFT)
	@echo "$(GREEN)$(GRAS)m➜ Cleaning $(NAME)" '♻️'
	@echo "$(GREEN)$(GRAS)m➜ $(NAME) cleaned" '✅' '.'

re: fclean all

.PHONY : all clean fclean
