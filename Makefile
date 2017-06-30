# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/29 19:13:14 by ggregoir          #+#    #+#              #
#    Updated: 2017/06/29 20:05:12 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ggregoir.filler

SRC		= srcs/main.c          \
		
OBJ		= $(patsubst srcs/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -g -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	@echo '\033[32m[ ✔ ] \n\033[0m' "Create filler"

obj/%.o: srcs/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	@echo '\033[0m[ ✔ ] \n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	@echo '\033[31m[ ✔ ] \n\033[0m' "Clean Lib"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	@echo '\033[31m[ ✔ ] \n\033[0m' "Fclean Lib"

re: fclean all

test: re
	@echo '\033[32m\n\033[0m' "-------------------------------------"
	./filler test

all: $(NAME)
	@re
.PHONY: clean fclean re all test
