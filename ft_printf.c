/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/04 12:40:46 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		which_conv(const char *str, va_list ap, t_struct ntm)
{
//	to_flag(ap, ntm);
	if (*str == 'c')
		conv_c(ap, ntm); // char
	else if (*str == 's')
		conv_s(ap, ntm); // char *
//	else if (*str == 'p')
//		conv_p(va_arg(ap, *ptr), ntm); // unsdint
	else if (*str == 'd')
		conv_d_u(ap, ntm); // int
//	else if (*str == 'i')
//		conv_i(va_list ap, ntm); // int 
//	else if (*str == 'u')
//		conv_d_u(va_arg(ap, int), ntm); // unsdint
//	else if (*str == 'x' || *str == 'X')
//		conv_x_X(va_arg(ap, int), ntm); // unsdint
//	else if (*str == '%')
//		conv_per(ap, ntm); // char
	return (1);
}

int		chaipas(const char *str, va_list ap)
{
	int	i;

	(void)ap;
	i = 0;
	t_struct ntm;
	ntm.final_len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (!ft_check_flag(&str[i], &ntm))
				return (ntm.final_len);
			i += which_flag(&str[i], &ntm) + 1;
			if (ft_is_conv(str[i]))
				i += which_conv(&str[i], ap, ntm);
		}
		else if (str[i] != '%')
		{
		//	printf("\\\\avant:%d//", ntm.final_len);
			ft_putchar(str[i], &ntm);
			i++;
		//	printf("\\\\apres:%d//", ntm.final_len);
		}
		//i++;
	}
	return (ntm.final_len);
}

int		ft_printf(const char *str, ...)
{ 
	int			final_lenght;

	va_list ap;
	va_start (ap, str);
	final_lenght = chaipas(str, ap);
	va_end(ap);
	printf("\nTaille finale retournee : %d.", final_lenght);
	return (final_lenght);
}

int		main()
{
	int test_d;

	test_d = 42;
//	ft_printf("On va tester cette merde = %d", 6);
//	write(1, "\n", 1);
	printf(KGRN"\n//!\\\\TAILLE PRINTF = %d.//!\\\\", ft_printf(KCYN"Mon printf : testons cette merde = %d", 6));
//	printf("%# -10.1d", -8, 10);
	return (0);
}

/*
**	printf("On va tester cette merde = %u", -8); => underflow, unsdint
*/