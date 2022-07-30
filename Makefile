# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 12:53:01 by florianma         #+#    #+#              #
#    Updated: 2021/09/30 21:03:37 by florianma        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =    srcs/error_management.c \
		  srcs/error_message.c \
		  srcs/extension_line.c \
		  srcs/ft_split.c \
		  srcs/ft_strjoin.c \
		  srcs/get_next_line.c \
		  srcs/main.c \
		  srcs/utils.c \
		  srcs/extract_img.c \
		  srcs/parsing.c \
		  srcs/mooves.c \
		  srcs/clean.c


OBJS         = ${SRCS:.c=.o}

PATH_MLX    = mlx_linux
CC             = gcc
CFLAGS        =  -std=c11 -Wall -Wextra -Werror -ggdb3
RM            = rm -f
NAME        = so_long
FLAGS        = -g -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm 
all:         ${NAME}

.c.o: 
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):     $(OBJS)
	make -C $(PATH_MLX)
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)
	@echo "\033[33;32m=== Compilation so_long \t\t\tOK! √\n"

bonus:        all

clean:
	make -C $(PATH_MLX) clean
	${RM} ${OBJS}

fclean:     clean
	make -C $(PATH_MLX) clean
	${RM} ${NAME}

re:         fclean all

.PHONY:        bonus all clean fclean re
