/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 09:45:59 by ldermign         ###   ########.fr       */
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

#define KRED  "\x1B[0;31m" // ROUGE
#define KGRN  "\x1B[0;32m" // VERT
#define KYEL  "\x1B[0;33m" // JAUNE
#define KBLU  "\x1B[0;34m" // BLEU
#define KMAG  "\x1B[0;35m" // MAGENTA
#define KCYN  "\x1B[0;36m" // CYAN
#define KWHT  "\x1B[0;37m" // BLANC
#define KGRE  "\x1b[1;30m" // VERT


# include <libc.h> /////////////////////////////////////////////////////////////


#define ERR(FILE, FUNC, LINE) printf(KYEL"%s:%s:%d\033[0m", FILE, FUNC, LINE)


int				ft_printf(const char *str, ...);

/*
**	Structures cspdiuxX%
*/

typedef	struct	s_struct
{
	int		final_len;
	int		i;
	int		j;
	int		minus;
	int		padded_zero;
	int		width;
	int		precision;
	int		nbr_width;
	int		nbr_precision;
	char	*str_of_flag;
	char	*str_precision;
	char	*str_width;
	char	*final_str_flag;
	size_t	size_final_str_flag;
}				t_flag_len;
void			ft_init_flag_len_flag(t_flag_len *flag);


/*
**	Checks
*/

int				ft_check_flag(const char *str);
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
void			ft_putnbr_adr(unsigned long nbr, t_flag_len *len);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_atoi_printf(char *str);
void			*ft_memmove(char *dst, char *src, size_t n);
void			*fill_from_end(char *dst, char *src, size_t n);
int				ft_atoi(char *str);
void			ft_fill_with_c(char *str, char c, int size);
void			join_str_width_and_precision(t_flag_len *flag);
char   			*fusion_conv_strflag(char *str, int nbr, t_flag_len *flag);
void			flip_zero_and_space(t_flag_len *flag);

/*
**	Flags
*/

void			string_of_flags(va_list ap, t_flag_len *flag);
int				which_flag(const char *str, t_flag_len *ntm);
// void			flag_minus(va_list ap, t_flag_len *ntm);
// void			flag_padded_zero(va_list ap, t_flag_len *ntm);
void			flag_precision(t_flag_len *flag);
void			flag_width(t_flag_len *flag);

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






void    ft_printf_monuq(t_flag_len ntm);





#endif
