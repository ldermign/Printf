# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    aout.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 12:13:17 by ldermign          #+#    #+#              #
#    Updated: 2021/02/02 14:00:34 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# make -C ./libft
rm a.out
clang -Wall -Wextra -Werror ./*.c -I ft_printf.h
# -I ft_printf.h ./libft/libft.a
# clear
./a.out
