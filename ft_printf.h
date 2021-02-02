/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/02 13:20:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>




# include <libc.h> /////////////////////////////////////////////////////////////



int				ft_printf(const char *str, ...);

/*
**	Structures cspdiuxX%
*/

typedef	struct	s_struct
{
	int final_len;
	int minus;
	int padded_zero;
	int width;
	int precision;
}				t_struct;
void			ft_init_struct_flag(t_struct *ntm);


/*
**	Checks
*/

int				ft_check_flag(const char *str, t_struct *flag);
int				ft_is_flag(char c);
int				ft_is_digit(char c);
int				ft_is_conv(char c);
int				ft_is_width(char c);

/*
**	Utils
*/

int				ft_atoi(const char *str);
void			ft_putchar(char c, t_struct *ntm);
void			ft_putstr(char *str, t_struct *ntm);
void			ft_bzer(void *str, size_t n);
size_t			ft_strlen(const char *str);

/*
**	Flags
*/

void			to_flag(t_struct flag, va_list ap);
int				which_flag(const char *str, t_struct *ntm);
void			flag_minus(va_list ap);
void			flag_padded_zero(va_list ap);
//void			flag_width(va_list ap);
void			flag_precision(va_list ap);

/*
**	Conversion
*/

void			which_conv(const char *str, va_list ap, t_struct ntm);
void			conv_int(va_list ap, t_struct flag);


/*
**	A SUPPRIMER
*/

//void	afficher_struct_conv(t_conversion conv);
void			afficher_struct_flags(t_struct ntm);








#endif
