/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/24 14:53:44 by ldermign         ###   ########.fr       */
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

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*s;
	size_t	n_bytes;

	i = 0;
	s = str;
	n_bytes = n;
	while (n_bytes > 0)
	{
		s[i] = '\0';
		i++;
		n_bytes--;
	}
}

void	ft_which_flag(const char *str, t_flags *flag)
{
	int i;

	i = 0;
	ft_bzero(flag, sizeof(t_flags));
	flag->padded_zero = -1;
	if (str)
	{
		i++;
		while (str[i] == '-' || str[i] == '0')
		{
			if (str[i] == '-') // forcement colle au nombre ?
				flag->minus = 1;
			if (str[i] == '0') // forcement colle au nombre ?
				flag->padded_zero = 1;
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
			{
				flag->widht = 1;
				while (str[i] >= '0' && str[i] <= '9')
					i++;
				if (str[i] == '.')
					flag->precision = 1;
			}
			// gerer *.* et *
			// *.nombre (pas neg)
			i++;
		}
	}
}

char	ft_widht();

void	afficher_flags_struct(t_flags flags)
	//simplement afficher la structure en fonction du flag
{
	printf("\nStructure = \n");
	printf("	minus = %d\n", flags.minus);
	printf("	padded_zero = %d\n", flags.padded_zero);
	printf("	widht = %d\n", flags.widht);
	printf("	precision = %d\n", flags.precision);
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
	ft_printf("On va tester %12cette merde");
//	printf("%# -10.1d", -8, 10);
	return (0);
}
