# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 16:41:45 by avenzel           #+#    #+#              #
#    Updated: 2017/02/16 18:20:24 by avenzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
LIBFT	= libft/libft.a

SRC		= fdf.c	fillxy.c	check_keys.c	draw_line.c	 free_functions.c	\
		  get_data.c	get_image_content.c	get_window.c	\
		  let_the_window_begin.c	verify.c

OBJ		= $(SRC:.c=.o)
CC		= gcc -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT) \
		-O3 -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) -c -o $@ $<

$(LIBFT)	:
	make -C libft/

lclean	:
	make -C libft/ clean

clean	: lclean
	rm -f *.o

fclean	: clean
	rm -f $(NAME)

re		: fclean all
