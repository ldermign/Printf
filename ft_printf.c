/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/01 22:18:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		which_conv(char c, va_list ap, t_struct ntm)
{
	
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
			i += which_flag(&str[i], &ntm);
			if (ft_is_conv(&str[i]))
				// which_conv(str, ap, ntm); conv de merde ekowfnerjialshgkjrtw;d shzglrikzs`l'char	*ft_itoa(int n)'jakqgof
			else if (str[i])
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
	printf("	widht = %d\n", ntm.widht);
	printf("	precision = %d\n", ntm.precision);
}

int		main()
{
	int test_d;

	test_d = 42;
	ft_printf("On va tester cette merde = %d", 8);
//	printf("On va tester cette merde = %d", 8);
//	printf("%# -10.1d", -8, 10);
	return (0);
}
