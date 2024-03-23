
CC			=	gcc

NAME			=	fdf

CFLAGS			=	-Wall -Wextra -Iinclude -ldl -lglfw -pthread -lm

SRC			=	fdf.c

MINILIBX		=	MLX42/build/libmlx42.a

OBJ_DIR			=	objs/

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RM			=	rm -rf

$(NAME):			$(OBJ_DIR) $(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(MINILIBX) -o $@

all:				$(NAME)

$(OBJ_DIR)%.o:%.c
				gcc $(CFLAGS) -I . -c $< -o $@
				$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(OBJ_DIR):	
				@mkdir -p $(OBJ_DIR)

clean:
				$(RM) $(OBJ)

fclean:				clean
				$(RM) $(OBJ) $(NAME) $(OBJ_DIR)
				

re:				fclean $(NAME)


.PHONY:			all clean fclean re
