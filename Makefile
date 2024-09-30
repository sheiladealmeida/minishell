# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 11:37:28 by shrodrig          #+#    #+#              #
#    Updated: 2024/05/30 20:57:36 by shrodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRC = main.c

OBJS = ${SRC:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

%.o : %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C ${LIBFT_PATH}
		${CC} ${OBJS} ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
		make -C ${LIBFT_PATH} clean
		${RM} ${OBJS}

fclean: clean
		make -C ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

