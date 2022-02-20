# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 17:44:49 by lcorinna          #+#    #+#              #
#    Updated: 2022/02/20 16:08:10 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_FDF = fdf

FDF = fdf.c exit.c pars.c checks.c struct.c htoi.c draw.c

OBJ_FDF = $(FDF:.c=.o)

CFLAG_MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g #Leaks --atExit -- ./fdf map.fdf

PATH_LIBFT = ./libft/

LIBFT = libft.a 

all: libmake $(NAME_FDF)

libmake: 
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)
		
$(NAME_FDF): $(OBJ_FDF)
	gcc $(CFLAGS) $(CFLAG_MLX) $(LIBFT) $(OBJ_FDF) -o $@

%.o: %.c fdf.h Makefile
	gcc $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ_FDF) $(LIBFT)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -f $(NAME_FDF)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all libmake clean fclean re