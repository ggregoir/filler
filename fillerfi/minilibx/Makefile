#
# **************************************************************************** #
#                                                                              #
#                :::       :::    :::        :::    :::                        #
#                :+::+: :+::+:    :+:         :+:  :+:                         #
#                +:+  +:+  +:+    +:+          +:+:+                           #
#                *+*   +   *+*    *+*            *                             #
#                +#+       +#+    +#+           #+#                            #
#                #+#       #+#    #+#         +#+#+#+                          #
#                ###       ###    #######   ####   ####                        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME =	libmlx.a

SRC =	mlx_shaders.c \
		mlx_new_window.m \
		mlx_init_loop.m \
		mlx_new_image.m \
		mlx_xpm.c \
		mlx_int_str_to_wordtab.c

OBJ1 =	$(SRC:.c=.o)
OBJ =	$(OBJ1:.m=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "=> \x1B[33mCompiling minilibx files...\x1b[37m\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "=> \x1B[32mlibmlx.a Ready !\x1B[37m"

clean:
	@printf "=> \x1B[31mDeleting minilibx .obj files...\x1B[37m\n"
	@rm -f $(NAME) $(OBJ) *~
	@rm -f mlx_app

re: clean all
