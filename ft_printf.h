/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/21 13:41:22 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>





#include <libc.h> //////////////////////

int					ft_printf(const char *, ...);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				ft_putstr(char *str);
size_t				ft_strlen(char *str);
typedef struct		ft_flags
{
	int minus;
	int sign_number;
	int space;
	int padded_zero;
	int prefix;
}					t_flags;

#endif
