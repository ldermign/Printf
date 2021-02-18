/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/18 15:00:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct_flag(t_flag_len *flag)
{ // eventuellement faire bzero pour faire plaisir a benji 
	flag->minus = 0;
	flag->padded_zero = 0;
	flag->width = -1;
	flag->precision = -1;
	flag->nbr_width = 0;
	flag->nbr_precision = 0;
	flag->str_precision = NULL;
	flag->str_width = NULL;
	flag->final_str_flag = NULL;
	flag->size_final_str_flag = 0;
	flag->conv_c = 0;
	flag->conv_s = 0;
	flag->conv_p = 0;
	flag->conv_d_i = 0;
	flag->conv_u = 0;
	flag->conv_x = 0;
	flag->conv_per = 0;
}

// char	*create_string_of_width_and_precision(char *str)
// {
// 	int		i;
// 	int		start;
// 	int		len_flag;
// 	char	*str_of_flag;

// 	i = 0;
// 	start = 0;
// 	len_flag = 0;
// 	if (str[i] == '0' || str[i] == '-')
// 	{
// 		i++;
// 		start++;
// 	}
// 	while (ft_is_flag(str[i]))
// 	{
// 		i++;
// 		len_flag++;
// 	}
// 	if ((str_of_flag = ft_calloc((len_flag + 1), sizeof(char))) == NULL)
// 		return (NULL);
// 	i = start;
// 	str_of_flag = ft_strncat(str_of_flag, &str[i], len_flag);
// 	return (str_of_flag);
// }

int		ft_nblen(long n)
{
	int len_int;

	len_int = 1;
	if (n < 0)
	{
		n = -n;
		len_int++;
	}
	while (n >= 10)
	{
		n /= 10;
		len_int++;
	}
	return (len_int);
}


void	string_of_flag_to_int(char *str, va_list ap, t_flag_len *flag)
{
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '0')
		i++;
	if (str[i] && str[i] == '*')
	{
		flag->nbr_width = va_arg(ap, int);
		// printf("flag->nbr_width = {%d}\n", flag->nbr_width);
		// printf("str[i] = {%c}\n", str[i]);
		i++;
	}
	else
	{
		flag->nbr_width = ft_atoi_printf(&str[i]);
		i += ft_nblen(flag->nbr_width) + 1;
	}
	if (flag->nbr_width < 0)
	{
		flag->nbr_width *= -1;
		flag->minus = 1;
	}
	if (str[i] && str[i] == '.')
		i++;
	if (str[i] == '*' && ++i)
		flag->nbr_precision = va_arg(ap, int);
	else
		flag->nbr_precision = ft_atoi_printf(&str[i]);
	if (flag->nbr_precision < 0)
		flag->nbr_precision *= -1;
	// printf("flag->nbr_width = {%d}\n", flag->nbr_width);
	// printf(KYEL"%s:%d:"CLR_COLOR" DEBUG\n", __func__, __LINE__);
}

int		which_flag(const char *str, va_list ap, t_flag_len *flag)
{
	int i;

	i = 0;
	ft_init_struct_flag(flag);
	string_of_flag_to_int((char*)str, ap, flag);
	if (str[i] == '-')
	{
		flag->minus = 1;
		i++;
	}
	if (str[i] == '0' && flag->minus == 0)
	{
		flag->padded_zero = 1;
		i++;
	}
	if (str[i] == '*' || ft_is_digit(str[i]))
	{
		flag->width = 1;
		i++;
		while (str[i] && ft_is_digit(str[i]))
			i++;
	}
	if (str[i] == '.' && (ft_is_digit(str[i + 1]) || str[i + 1] == '*'))
	{
		flag->precision = 1;
		i++;
	}
	if (str[i] == '.')
		i++;
	if (str[i] == '*' || ft_is_digit(str[i]))
	{
		i++;
		while (str[i] && ft_is_digit(str[i]))
			i++;
	}
	// printf(KYEL"%s:%d:"CLR_COLOR" DEBUG\n", __func__, __LINE__);
	return (i);
}
