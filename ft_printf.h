/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/11 15:07:01 by ldermign         ###   ########.fr       */
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

#define KRED  "\x1B[0;31m"
#define KGRN  "\x1B[0;32m"
#define KYEL  "\x1B[0;33m"
#define KBLU  "\x1B[0;34m"
#define KMAG  "\x1B[0;35m"
#define KCYN  "\x1B[0;36m"
#define KWHT  "\x1B[0;37m"
#define KGRE  "\x1b[1;30m"
//printf("%sred\n", KRED);


# include <libc.h> /////////////////////////////////////////////////////////////


#define ERR(FILE, FUNC, LINE) printf(KYEL"%s:%s:%d\033[0m", FILE, FUNC, LINE)


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
}				t_flag_len;
void			ft_init_flag_len_flag(t_flag_len *flag);


/*
**	Checks
*/

int				ft_check_flag(const char *str, t_flag_len *flag);
int				ft_is_flag(char c);
int				ft_is_digit(char c);
int				ft_is_conv(char c);
int				ft_is_width(char c); //largeur
int				ft_is_all(char c);

/*
**	Utils
*/

void			ft_putchar(char c, t_flag_len *len);
void			ft_putstr(char *str, t_flag_len *len);
size_t			ft_strlen(const char *str);
char			*ft_itoa(int nb);
char			*ft_itoa_base(size_t nb, char *base);
void			ft_putnbr_base_printf(long nbr, char *base, t_flag_len *len);
char			*ft_strcat(char *dst, char *src);
char			*ft_strncat(char *dst, char *src, size_t nb);
void			ft_putnbr(unsigned int nbr, t_flag_len *len);
void			ft_putnbr_adr(unsigned int nbr, t_flag_len *len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_rev_string(char *str, int size);

/*
**	Flags
*/

char			*to_flag(char *str, va_list ap, t_flag_len *flag);
int				which_flag(const char *str, t_flag_len *ntm);
void			flag_minus(va_list ap, t_flag_len *ntm);
void			flag_padded_zero(va_list ap, t_flag_len *ntm);
void			flag_width(va_list ap, t_flag_len *ntm);
void			flag_precision(va_list ap, t_flag_len *ntm);

/*
**	Conversion
*/

int				which_conv(const char *str, va_list ap, t_flag_len *ntm);
void			conv_d_i(va_list ap, t_flag_len *flag);
void			conv_s(va_list ap, t_flag_len *flag);
void			conv_c(va_list ap, t_flag_len *flag);
void			conv_u(va_list ap, t_flag_len *flag);
void			conv_per(t_flag_len *flag);
void			conv_x_X(char c, va_list ap, t_flag_len *len);
void			conv_p(va_list ap, t_flag_len *flag);












#endif
