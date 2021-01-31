/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/31 12:15:05 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>





#include <libc.h> //////////////////////////////////////////////////////////////

int					ft_printf(const char *, ...);

/*
**	Conversion
*/



/*
**	Checks
*/

int					ft_check_flag(const char *str);
int					ft_is_flag(char c);
int					ft_is_digit(char c);
int					ft_is_conv(char c);
int 				ft_is_width(char c);

/*
**	Utils
*/

void				ft_putnbr(int nb);
int					ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_bzer(void *str, size_t n);
size_t				ft_strlen(const char *str);

/*
**	Structures
*/

typedef struct		ft_flags
{
	int minus;
	int padded_zero;
	int widht;
	int precision;
}					t_flags;
typedef struct		ft_conversion
{
	int cara_c;
	int string_s;
	int point_ad_hex_p;
	int int_dec_d;
	int int_dec_i;
	int unsd_int_u;
	int unsd_hex_x;
	int unsd_hex_X;
	int percent;
}					t_conversion;
void				ft_init_struct_flag(t_flags *flag);
void				ft_init_struct_conversion(t_conversion *conv);
int 				ft_which_flag(const char *str, t_flags *flag);
int					ft_which_print(const char *str, t_conversion *conv);

/*
**	A SUPPRIMER
*/

void	afficher_struct_conv(t_conversion conv);
void	afficher_struct_flags(t_flags flags);

#endif