NAME = "RTV1"

SRC =	src/main.c \
		src/ini.c \
		src/error.c \
		src/create_object.c \
		src/raytracing.c \
		src/ft_check_object.c \
		src/key.c 

LIBS = -framework OpenGL -framework Appkit minilibx_macos/libmlx.a libft/libft.a

OBJ =	$(patsubst src/%.c,obj/%.o,$(SRC))

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
		make -C libft/
		make -C minilibx_macos/
		gcc $(LIBS) $(OBJ) -o $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
	make -C libft/ clean
	/bin/rm -rf obj

fclean : clean
	make -C libft/ fclean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean
