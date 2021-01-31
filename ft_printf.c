/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/31 14:20:30 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		chaipas(const char *str, va_list ap)
{
	int			i;
	int			len;
	const char *temp;

	i = 0;
	len = 0;
	temp = str;
	t_flags flags;
	t_conversion conv;
/*	while (temp)
	{
		if (!ft_check_all(str, flags, conv))
			return (-1);
		temp++;
	}*/
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			i += ft_which_flag(&str[i], &flags) + ft_which_print(&str[i], &conv);
	//		va_arg(ap, str);
		}
		if (str[i] != '%')
			len += ft_putchar(str[i]);	
		i++;
	}
	return (len);
}

int		ft_printf(const char *str, ...)
{ 
	int			final_lenght;

	final_lenght = 0;
	va_list ap;
	va_start (ap, str);
	final_lenght = chaipas(str, ap);
	va_end(ap);
	return (final_lenght);
}

/*
int		ft_check_all(const char *str, t_flags *flag, t_conversion *conv)
{
	ft_check_flag(str, flag, conv)
	{
		ft_init_struct_conversion(conv);
		ft_which_print(str, conv);
		ft_init_struct_flag(flag);
		ft_which_flag(str, flag);
	}
	return (1);
}*/

int		main()
{
	int test_d;

	test_d = 42;
//	ft_printf("On va tester cette merde = %08%");
	printf("On va tester cette merde = %tttt", 8);
//	printf("%# -10.1d", -8, 10);
	return (0);
}



/*
**	flag '0' is ignored when flag '-' is present
**	
**	
**	
**	
*/