/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:05:57 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/01 22:32:29 by ldermign         ###   ########.fr       */
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
**	Structures cspdiuxX%
*/

typedef struct		s_ptrf
{
	char	c;
	void	(*f)();
}					t_ptrf;

typedef struct		ft_struct
{
	int final_len;
	int minus;
	int padded_zero;
	int widht;
	int precision;
}					t_struct;

void				ft_init_struct_flag(t_struct *ntm);
int 				which_flag(const char *str, t_struct *ntm);
int					which_conv(const char *str, va_list ap);


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

int					ft_atoi(const char *str);
void		ft_putchar(char c, t_struct *ntm);
void				ft_putstr(char *str);
void				ft_bzer(void *str, size_t n);
size_t				ft_strlen(const char *str);

/*
**	Conversion
*/

char	*ft_itoa(int n);

/*
**	A SUPPRIMER
*/

//void	afficher_struct_conv(t_conversion conv);
void	afficher_struct_flags(t_struct ntm);

#endif