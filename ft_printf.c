/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:49:07 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/28 13:54:23 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_flag(const char *str)
{
	if (*str == '-' || *str == '0' || *str == '*'
		|| (*str >= '0' && *str <= '9') || *str == '.')
		return (1);
	return (0);
}

void	afficher_struct_flags(t_flags flags)
// afficher structure flag
{
	printf("\nStructure flag :\n");
	printf("	minus = %d\n", flags.minus);
	printf("	padded_zero = %d\n", flags.padded_zero);
	printf("	widht = %d\n", flags.widht);
	printf("	precision = %d\n", flags.precision);
}

void	afficher_struct_conv(t_conversion conv)
// afficher structure de conversion
{
	printf("\nStructure conversion :\n");
	printf("	cara_c = %d\n", conv.cara_c);
	printf("	string_s = %d\n", conv.string_s);
	printf("	point_ad_hex_p = %d\n", conv.point_ad_hex_p);
	printf("	int_dec_d = %d\n", conv.int_dec_d);
	printf("	int_dec_i = %d\n", conv.int_dec_i);
	printf("	unsd_int_u = %d\n", conv.unsd_int_u);
	printf("	unsd_hex_x = %d\n", conv.unsd_hex_x);
	printf("	unsd_hex_X = %d\n", conv.unsd_hex_X);
}

void	ft_init_struct_conversion(t_conversion *conv)
// initialiser structure de conversion
{
	conv->cara_c = 0;
	conv->string_s = 0;
	conv->point_ad_hex_p = 0;
	conv->int_dec_d = 0;
	conv->int_dec_i = 0;
	conv->unsd_int_u = 0;
	conv->unsd_hex_x = 0;
	conv->unsd_hex_X = 0;
}

void	ft_init_struct_flag(t_flags *flag)
// initialiser structure de flag
{
	flag->minus = 0;
	flag->padded_zero = -1;
	flag->widht = 0;
	flag->precision = 0;
}

int		ft_check_flag(const char *str)
{
	if (!((*str >= '0' && *str <= '9') || *str == '0' || *str == '-'))
		return (-1);
	else if (!(*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
	|| *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X'))
		return (-1);
	str++;
	if (!(*str != '.' || *str != '*' || *str != 'c' || *str != 's' || *str != 'p'
	|| *str != 'd' || *str != 'i' || *str != 'u' || *str != 'x' || *str != 'X'))
		return (-1);
	return (1);
}

int	ft_which_print(const char *str, t_conversion *conv)
{
	ft_init_struct_conversion(conv);
//	if (ft_check_flag(str) == -1)
//		return (MSG_ERROR);
	if (str)
	{
		str++;
		while (ft_is_flag(str))
			str++;
		if (*str == 'c')
			conv->cara_c = 1;
		else if (*str == 's')
			conv->string_s = 1;
		else if (*str == 'p')
			conv->point_ad_hex_p = 1; // comme x avec 0x devant
		else if (*str == 'd')
			conv->int_dec_d = 1;
		else if (*str == 'i')
			conv->int_dec_i = 1;
		else if (*str == 'u')
			conv->unsd_int_u = 1;
		else if (*str == 'x')
			conv->unsd_hex_x = 1;
		else if (*str == 'X')
			conv->unsd_hex_X = 1;
	}
	afficher_struct_conv(*conv); //////////////////////////////////////////////
	return (1);
}


int ft_which_flag(const char *str, t_flags *flag)
{
	int avancement;

	avancement = ft_strlen(str);
	ft_init_struct_flag(flag);
	if (str)
	{
		str++;
		while (*str == '-' || *str == '0' || *str == '*'
		|| (*str >= '0' && *str <= '9'))
		{
			if (*str == '-')
				flag->minus = 1;
			if (*str == '0')
				flag->padded_zero = 1;
			if ((*(str + 1) == '.' && (*str >= '0' && *str <= '9')) || *str == '*')
			{
				flag->widht = 1;
				while ((*str >= '0' && *str <= '9') || *str == '*')
					str++;
				if (*str == '.' && ((*(str + 1) >= '0' && *(str + 1) <= '9')
				|| *(str + 1) == '*'))
					flag->precision = 1;
			}
			str++;
		}
	}
	afficher_struct_flags(*flag);
	return (avancement -= ft_strlen(str));
}

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

