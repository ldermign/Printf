/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/21 13:48:24 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	ft_afficher(const char *str)
{
	int size;
	int i;

	size = 0;
	i = 0;
//	printf("Voici la chaine :");
//	ft_putstr(str);
	printf("\n");
	while (str[size])
		size++;
	printf("Taille de la chaine envoyee = %d.\n", size);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '0'
				|| str[i] == '#')
			printf("Il y a un flag : %c", str[i]);
		i++;
	}
}

int		ft_size_str(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_conversion(char c)
{
	if (c == 'c')
		ft_conversion_char();
	else if (c == 's')
		ft_conversion_string();
	else if (c == 'p')
		ft_conversion_adress();
	else if (c == 'd')
		ft_conversion_int_deci();
	else if (c == 'i')
		ft_conversion_int();
	else if (c == 'u')
		ft_conversion_unsigned_int();
	else if (c == 'x' || c == 'X')
		ft_conversion_unsigned_int_hexa();
}


char	ft_conversion_char()
{}

char	*ft_conversion_string()
{}

void	ft_flag()
{}

char	ft_flag_space(char *str)
{

}*/

void	ft_init_struct(t_flags *flag)
{
	flag->minus = 0;
	flag->padded_zero = 0;
	flag->sign_number = 0;
	flag->space = 0;
	flag->prefix = 0;
}

void	ft_which_flag(const char *str, t_flags *flag)
{
	int i;

	i = 0;
	ft_init_struct(flag);
	if (str)
	{
		i++;
		while (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '0'
				|| str[i] == '#')
		{
			if (str[i] == '-')
				flag->minus = 1;
			if (str[i] == '+')
				flag->sign_number = 1;
			if (str[i] == ' ')
				flag->space = 1;
			if (str[i] == '0')
				flag->padded_zero = 1;
			if (str[i] == '#')
				flag->prefix = 1;
			i++;
		}
	}
}

void	afficher_flags_struct(t_flags flags)
	//simplement afficher la structure en fonction du flag
{
	printf("\nStructure = \n");
	printf("   minus = %d\n", flags.minus);
	printf("   sign_number = %d\n", flags.sign_number);
	printf("   space = %d\n", flags.space);
	printf("   padded_zero = %d\n", flags.padded_zero);
	printf("   prefix = %d\n", flags.prefix);
}

int		ft_printf(const char *str, ...)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	va_list ap;
	va_start (ap, str);
	t_flags flags;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			ft_which_flag(&str[i], &flags);
			afficher_flags_struct(flags);
		}
		if (str[i] != '%')
			ft_putchar(str[i]);	
		i++;
	}
	va_end(ap);
	return (ft_strlen((char*)str));
}

int		main()
{
	int test_d;

	test_d = 42;
	ft_printf("On va tester cette merde = %d", test_d);
	return (0);
}
