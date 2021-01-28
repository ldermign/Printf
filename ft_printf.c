/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/28 16:00:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{ 
	int	i;

	i = 0;
	va_list ap;
	va_start (ap, str);
	t_flags flags;
	t_conversion conv;
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			i += ft_which_flag(&str[i], &flags) + ft_which_print(&str[i], &conv);
	//		va_arg(ap, str);
		}
		if (str[i] != '%')
			ft_putchar(str[i]);	
		i++;
	}
	va_end(ap);
	return (ft_strlen(str)); // return taille chaine affiche
}

int		main()
{
	int test_d;

	test_d = 42;
	ft_printf("On va tester cette merde = %0-9.*X test");
//	printf("On va tester cette merde = %8.*d", 8, 42);
//	printf("%# -10.1d", -8, 10);
	return (0);
}

