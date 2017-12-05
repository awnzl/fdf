# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 16:41:45 by avenzel           #+#    #+#              #
#    Updated: 2017/12/05 20:06:07 by avenzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
LIBFT	= libft/libft.a

SRC		= fdf.c	fillxy.c	check_keys.c	draw_line.c	 free_functions.c	\
		  get_data.c	get_image_content.c	get_window.c	\
		  let_the_window_begin.c	verify.c

INCDIR	= ./inc
SRCDIR	= ./src
OBJDIR	= ./obj

CC		= gcc -Wall -Wextra -Werror

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

$(NAME)	: obj $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT) \
		-O3 -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

all		: $(NAME)

obj		:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -I $(INCDIR) -I ./libft -I ./minilibx_macos -o $@ -c $<

$(LIBFT)	:
	@make -C libft/

$(MLX)		:
	@make -C minilibx_macos/

lclean	:
	@make -C libft/ fclean
	@make -C minilibx_macos/ fclean

clean	: lclean
	rm -rf $(OBJDIR)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
