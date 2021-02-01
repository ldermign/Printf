# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    aout.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 12:13:17 by ldermign          #+#    #+#              #
#    Updated: 2021/02/01 21:40:32 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# make -C ./libft
clang -Wall -Wextra -Werror ft_printf.h afficher_printf_supp.c ft_printf.c ft_printf_utils.c struct.c check.c 
# -I ft_printf.h ./libft/libft.a
# clear
./a.out
