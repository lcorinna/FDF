# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 17:44:49 by lcorinna          #+#    #+#              #
#    Updated: 2022/02/14 19:18:13 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PIPEX = fdf

PIPEX = fdf.c exit.c checks.c

OBJ_PIPEX = $(PIPEX:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g #Leaks --atExit -- ./fdf

PATH_LIBFT = ./libft/

LIBFT = libft.a 

all: libmake $(NAME_PIPEX)

libmake: 
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(LIBFT) $(LIBFT)
		
$(NAME_PIPEX): $(OBJ_PIPEX)
	gcc $(CFLAGS) $(LIBFT) $(OBJ_PIPEX) -o $@

%.o: %.c pipex.h Makefile
	gcc $(CFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJ_PIPEX) $(LIBFT)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME_PIPEX)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all libmake clean fclean re