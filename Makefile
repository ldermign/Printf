# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 09:47:47 by ldermign          #+#    #+#              #
#    Updated: 2021/01/05 10:23:22 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_printf.a

SRCS_PRINTF	=	// sources .

SRCS_LIBFT	=	./libft

SRCS_CONV	=	./conversion

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

${NAME}

all:		${NAME}

clean:		rm -rf ${}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
