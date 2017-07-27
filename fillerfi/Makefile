# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 16:05:27 by jafaghpo          #+#    #+#              #
#    Updated: 2017/07/27 13:26:48 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		jafaghpo.filler

SRC_PATH =	./src/
OBJ_PATH =	./obj/
INC_PATH =	./include/ ./libft/includes/ ./minilibx/
LIB_PATH =	./libft/ ./minilibx/

SRC_NAME =	main.c parse.c tools.c place.c graph.c
OBJ_NAME =	$(SRC_NAME:.c=.o)
LIB_NAME =	-lft -lmlx

DEP =		include/filler.h

SRC =		$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC =		$(addprefix -I,$(INC_PATH))
LIB =		$(addprefix -L,$(LIB_PATH))

CC	=		gcc -Ofast
CFLAGS =	-Wall -Wextra -Werror
FRAMEWORK =	-framework OpenGL -framework AppKit

all: lib void $(NAME) done

void:
	@printf "\n\x1B[33mᚔᚔᚔᚔᚔᚔ Make Filler ᚔᚔᚔᚔᚔᚔ\e[0m\n"
	@printf "=> \e[38;5;208mMaking filler obj files... \x1B[37m"

done:
	@printf "\n=> done.\n"
	@printf "\n\x1B[32mᚔᚔᚔᚔᚔᚔ Compilation done ! ᚔᚔᚔᚔᚔᚔ\e[0m\n"

$(NAME): $(OBJ)
	@$(CC) $(LIB) $(LIB_NAME) $(FRAMEWORK) $^ -o $@
	@printf "\n=> \x1B[33mCompiling filler files... \e[0m"
	@printf "\n=> \x1B[32mExecutable jafaghpo.filler ready !\x1B[37m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(DEP)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

lib:
	@printf "\n\x1B[33mᚔᚔᚔᚔᚔᚔ Make Libs ᚔᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C ./libft/
	@make -C ./minilibx/
	@printf "\n=> done.\n"

clean:
	@printf "\n\x1B[33mᚔᚔᚔᚔᚔᚔ Clean Filler ᚔᚔᚔᚔᚔᚔ\x1b[37m\n"
	@rm -rf $(OBJ) $(OBJ_PATH)
	@printf "=> \x1B[31mDeleting filler .obj files...\x1B[37m\n"
	@make -C ./libft/ clean
	@make -C ./minilibx/ clean

fclean: clean
	@rm -f $(NAME)
	@printf "=> \x1B[31mDeleting filler executable...\x1B[37m\n"
	@make -C ./libft/ fclean
	@printf "=> done.\n"

re: fclean all

.PHONY: lib clean fclean re
