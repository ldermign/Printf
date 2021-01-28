/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/28 13:54:25 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//# define MSG_ERROR -1


#include <libc.h> //////////////////////

int					ft_printf(const char *, ...);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_bzer(void *str, size_t n);
size_t				ft_strlen(const char *str);
typedef struct		ft_flags
{
	int minus;
	int padded_zero;
	int widht;
	int precision;
}					t_flags;
typedef struct	ft_conversion
{
	int cara_c;
	int string_s;
	int point_ad_hex_p;
	int int_dec_d;
	int int_dec_i;
	int unsd_int_u;
	int unsd_hex_x;
	int unsd_hex_X;
}					t_conversion;

#endif