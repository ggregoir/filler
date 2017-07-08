# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 18:41:23 by jafaghpo          #+#    #+#              #
#    Updated: 2017/07/08 15:34:02 by ggregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRC =		src/ft_memset.c src/ft_bzero.c src/ft_memchr.c src/ft_memcpy.c src/ft_strcpy.c \
			src/ft_strcmp.c src/ft_memmove.c src/ft_memccpy.c src/ft_memset.c src/ft_strncpy.c \
			src/ft_tolower.c src/ft_toupper.c src/ft_putchar.c src/ft_putstr.c src/ft_itoa.c \
			src/ft_strdup.c src/ft_strlen.c src/ft_putnbr.c src/ft_memcmp.c src/ft_putendl.c \
			src/ft_strcat.c src/ft_strncat.c src/ft_atoi.c src/ft_isdigit.c src/ft_strncmp.c \
			src/ft_isalpha.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c src/ft_strchr.c \
			src/ft_strrchr.c src/ft_strstr.c src/ft_strlcat.c src/ft_strnstr.c src/ft_putchar_fd.c\
			src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_memalloc.c \
			src/ft_memdel.c src/ft_strnew.c src/ft_strdel.c src/ft_strclr.c src/ft_striter.c \
			src/ft_striteri.c src/ft_strmap.c src/ft_strmapi.c src/ft_strequ.c src/ft_strnequ.c \
			src/ft_strsub.c src/ft_strjoin.c src/ft_strtrim.c src/ft_strsplit.c src/ft_lstnew.c \
			src/ft_lstdelone.c src/ft_lstdel.c src/ft_lstadd.c src/ft_lstiter.c src/ft_lstmap.c \
			src/ft_isupper.c src/ft_islower.c src/ft_isspace.c src/ft_strjoin_free.c \
			src/ft_putnstr.c src/ft_strcut.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
REM		= 	ft_bzero.o ft_memchr.o ft_memcpy.o ft_strcpy.o \
			ft_strcmp.o ft_memmove.o ft_memccpy.o ft_memset.o ft_strncpy.o \
			ft_tolower.o ft_toupper.o ft_putchar.o ft_putstr.o ft_itoa.o \
			ft_strdup.o ft_strlen.o ft_putnbr.o ft_memcmp.o ft_putendl.o \
			ft_strcat.o ft_strncat.o ft_atoi.o ft_isdigit.o ft_strncmp.o \
			ft_isalpha.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strchr.o \
			ft_strrchr.o ft_strstr.o ft_strlcat.o ft_strnstr.o ft_putchar_fd.o\
			ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_memalloc.o \
			ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o \
			ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o \
			ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_lstnew.o \
			ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
			ft_isupper.o ft_islower.o ft_isspace.o ft_strjoin_free.o \
			ft_putnstr.o ft_strcut.o \

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	rm $(REM)
	@echo '\033[32m[ ✔ ] \033[0m' "Creating lib \n"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -o $@ -c $<

clean:
	/bin/rm -rf obj/
	@echo '\033[0m' "Cleaning lib..."          

fclean:
	/bin/rm -f $(NAME)
	@echo '\033[0m' "Fcleaning lib..."

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all test
