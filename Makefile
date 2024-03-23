# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akloster <akloster@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 10:23:17 by akloster          #+#    #+#              #
#    Updated: 2024/03/23 10:23:17 by akloster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

NAME			=	fdf

CFLAGS			=	-Wall -Wextra -Werror

SRC				=	fdf.c 

SRC_GNL			= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ_DIR			=	objs/

OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))


RM				=	rm -rf

$(NAME):			$(OBJ_DIR) $(OBJ)
					make -C ./minilibx
					$(CC) $(CFLAGS) $(SRC_GNL) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

all:				$(NAME)

$(OBJ_DIR)%.o:%.c
					$(CC) $(CFLAGS) -I . -c $< -o $@

%.o: %.c
					$(CC) $(CFLAGS) -Imlx -c $< -o $@


$(OBJ_DIR):	
					@mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ)
					make clean -C ./minilibx

fclean:				clean
					$(RM) $(OBJ) $(NAME) $(OBJ_DIR)
				
				

re:				fclean $(NAME)


.PHONY:			all clean fclean re
