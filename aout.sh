# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    aout.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 12:13:17 by ldermign          #+#    #+#              #
#    Updated: 2021/02/25 09:18:43 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# make -C ./libft
rm a.out
#clang -fsanitize=address -g3 -Wall -Wextra -Werror ./*.c -I ft_printf.h
gcc ./*.c -I ft_printf.h
# -I ft_printf.h ./libft/libft.a
# clear
./a.out
