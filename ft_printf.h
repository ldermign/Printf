/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/04 12:46:23 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>


/*
**	TEJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
*/

#define KRED  "\x1B[1;31m"
#define KGRN  "\x1B[1;32m"
#define KYEL  "\x1B[1;33m"
#define KBLU  "\x1B[1;34m"
#define KMAG  "\x1B[1;35m"
#define KCYN  "\x1B[1;36m"
#define KWHT  "\x1B[1;37m"
//	printf("%sred\n", KRED);


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

void			ft_putchar(char c, t_struct *ntm);
void			ft_putstr(char *str, t_struct *ntm);
void			ft_bzer(void *str, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);

/*
**	Flags
*/

void			to_flag(t_struct flag, va_list ap);
int				which_flag(const char *str, t_struct *ntm);
void			flag_minus(va_list ap);
void			flag_padded_zero(va_list ap);
void			flag_width(va_list ap, t_struct *ntm);
void			flag_precision(va_list ap);

/*
**	Conversion
*/

int				which_conv(const char *str, va_list ap, t_struct ntm);
void			conv_d_u(va_list ap, t_struct flag);
void			conv_s(va_list ap, t_struct flag);
void			conv_c(va_list ap, t_struct flag);
void			conv_per(va_list ap, t_struct flag);












#endif
