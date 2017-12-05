# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 16:41:45 by avenzel           #+#    #+#              #
#    Updated: 2017/12/05 19:49:36 by avenzel          ###   ########.fr        #
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

$(NAME)	: obj $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT) \
		-O3 -lmlx -framework OpenGL -framework AppKit

all		: $(NAME)

obj		:
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) -I $(INCDIR) -I ./libft -o $@ -c $<

$(LIBFT)	:
	@make -C libft/

lclean	:
	@make -C libft/ clean

clean	: lclean
	rm -rf $(OBJDIR)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
