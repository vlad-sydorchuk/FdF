#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 08:42:30 by vsydorch          #+#    #+#              #
#    Updated: 2017/04/19 10:10:10 by vsydorch         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
LIB = libft/libft.a
SRCS =  srcs/main.c srcs/errors.c srcs/ft_split_cl.c srcs/fill_map.c \
		srcs/ft_atoi_base.c srcs/alg.c srcs/hooks.c srcs/prj.c srcs/ft_drw.c
HEADERS = includes/fdf.h
FLAGS = -Wall -Wextra -Werror -g
FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit
BINS = $(SRCS:.c=.o)
all: $(NAME)
libclean:
	make -C libft/ clean
libfclean:
	make -C libft/ fclean
$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
clean: libclean
	/bin/rm -f $(BINS)
fclean: libfclean clean
	/bin/rm -f $(NAME)
re: fclean all