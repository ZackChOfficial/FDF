# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 11:39:45 by zchatoua          #+#    #+#              #
#    Updated: 2019/01/21 11:52:25 by zchatoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : libft
	gcc $(FLAGS) -I /usr/local/include *.c *.o  -o $@ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

libft:
	gcc $(FLAGS) -c get_next_line/*.c get_next_line/libft/*.c

re: fclean $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
