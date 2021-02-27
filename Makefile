# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 09:47:47 by ldermign          #+#    #+#              #
#    Updated: 2021/02/27 12:48:45 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	check.c \
				conversion_p_d_i_u_x.c \
				conversion_s_c_per.c \
				ft_printf.c \
				fusion_strflag_conv_c_p.c \
				fusion_strflag_conv_s_d_i_u.c \
				fusion_strflag_conv_s_utils.c \
				init_flags.c \
				join_width_preci.c \
				utils.c \
				utils_itoa.c \
				utils_size.c

OBJS		=	${SRCS:.c=.o}

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

LIBC		=	ar rc

LIBR		=	ranlib

RM			=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

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
