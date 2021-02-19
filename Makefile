# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 09:47:47 by ldermign          #+#    #+#              #
#    Updated: 2021/02/19 08:33:01 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	check.c conv1.c flags.c ft_printf_utils.c ft_printf.c \
				join_width_precision.c struct_flag.c fusion.c

OBJS		=	${SRCS:.c=.o}

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

LIBC		=	ar rc

LIBR		=	ranlib

RM			=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME):	${OBJS} ./ft_printf.h
			${LIBC} ${NAME} ${OBJS}
			${LIBR}	${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
