/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/02 13:58:22 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		which_conv(const char *str, va_list ap, t_struct ntm)
{
	char cara;

	cara = (int)*str;
	/*if (cara == 'c')
		//fonction c
	else if (cara == 's')
		//fonction s
	else if (cara == 'p')
		//fonction p*/
	if (cara == 'd')
		conv_int(ap, ntm);
	/*else if (cara == 'i')
		//fonciton i
	else if (cara == 'u')
		//fonction u
	else if (cara == 'x' || cara == 'X')
		//fonction x || X
	else if (cara == '%')
		//fonction %*/
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
			i += which_flag(&str[i], &ntm);
			if (ft_is_conv((char)&str[i]))
				//return (0);
				which_conv(&str[i], ap, ntm);
			if (str[i])
				ft_putchar(str[i], &ntm);
		}
		if (str[i] != '%')
			ft_putchar(str[i], &ntm);
		i++;
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
	printf("\nTaille finale retournee : %d", final_lenght);
	return (final_lenght);
}

void	afficher_struct_flags(t_struct ntm)
{
	printf("\nStructure flag :\n");
	printf("	minus = %d\n", ntm.minus);
	printf("	padded_zero = %d\n", ntm.padded_zero);
	printf("	width = %d\n", ntm.width);
	printf("	precision = %d\n", ntm.precision);
}

int		main()
{
	int test_d;

	test_d = 42;
	ft_printf("On va tester cette merde = %*d", 8, 12);
//	printf("On va tester cette merde = %-8d", 45);
//	printf("%# -10.1d", -8, 10);
	return (0);
}
