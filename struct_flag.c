/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/12 17:46:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string_of_flags(char *str)
{
	int len_flag;
	char *str_of_flag;
	int i;

	i = 0;
	len_flag = 0;
	str--;
	while (ft_is_conv(*str) && str--)
		len_flag++;
	if ((str_of_flag = (char*)malloc(sizeof(char) * (len_flag + 1))) == NULL)
		return (NULL);
	str++;
	str_of_flag = ft_strcat(str_of_flag, str);
	return (str);
}

char	*flag_width(char *str, size_t len_str, va_list ap, t_flag_len *flag)
{
	(void)ap;
	char	*space_or_zero;
	char	*str_width;
	size_t	i;
	size_t	int_width;

	space_or_zero = " ";
	i = 0;
	if (flag->padded_zero == 1)
		space_or_zero = "0";
	while (i < len_str)
	{
		if (ft_is_digit(*str))
			int_width = ft_atoi_printf(str);
		i++;
	}
	if ((str_width = (char*)malloc(sizeof(char) * (int_width + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < int_width)
	{
		str_width = ft_strcat(str_width, space_or_zero);
		i++;
	}
	return (str_width);
}

char	*to_flag(char *str, va_list ap, t_flag_len *flag)
{
	char	*str_of_flag;
	char	*str_flag_conv;
	size_t	size_str_flag;

	
	str_flag_conv = NULL;
	if (flag->minus == 1 && flag->padded_zero == 1)
		flag->padded_zero = 0;
	str_of_flag = string_of_flags(str);
	size_str_flag = ft_strlen(str_of_flag);
	if (flag->width == 1 || flag->padded_zero == 1)
		str_flag_conv = flag_width(str_of_flag, size_str_flag, ap, flag);

	// if (flag->minus == 1)
	// 	flag_minus(str, len_str);
	// if (flag->padded_zero == 1)
	// 	flag_padded_zero(str, len_str);
	// if (flag->precision == 1)
	// 	flag_precision(str, len_str);
	return (str_flag_conv);
}

	// retourne la chaine avec flag,
	// utilisee ensuite dans les conversionpour changer le print

void	ft_init_struct_flag(t_flag_len *flag)
{
	flag->minus = 0;
	flag->padded_zero = 0;
	flag->width = 0;
	flag->precision = 0;
}

int which_flag(const char *str, t_flag_len *flag)
{
	int avancement;

	avancement = ft_strlen(str);
	ft_init_struct_flag(flag);
	while (ft_is_flag(*str))
	{
		if (*str == '-')
			flag->minus = 1;
		if (*str == '0')
			flag->padded_zero = 1;
		if (*str == '*' || ft_is_digit(*str))
		{
			flag->width = 1;
			while (*str == '*' || ft_is_digit(*str))
				str++;
			if (*str == '.' && (ft_is_digit(*(str + 1))
			|| *(str + 1) == '*'))
				flag->precision = 1;
		}
		str++;
	}
	avancement -= ft_strlen((str) - 1);
	return (avancement);
}

int		ft_check_flag(const char *str)
{
	str++;
	if (!ft_is_flag(*str) || !ft_is_conv(*str))
		return (-1);
	while (ft_is_flag(*str) || ft_is_conv(*str))
	{
		if (*(str - 1) == '%' && *str == '0' && ft_is_digit(*(str + 1)))
			return (-1);
		if (ft_is_digit(*str) && *(str + 1) == '*')
			return (-1);
		if (*str == '*' && ft_is_digit(*(str + 1)))
			return (-1);
		str++;
	}
	return (1);
}

	// while ((i < len_flag) && i++)
	// 	str++;
	// printf("=========len_flag = %d=========\n", len_flag);
	// str_of_flag = ft_rev_string(str, len_flag);
	// printf(KRED"flags = ||%s||\n", str_of_flag);
	// printf("emplacement str apres [%c]\n", *str);
	// return (char*)(str);
	// char *temp;
	// int i = 0;
	// int len_flags = 0;
	// while (ft_is_flag(*str))
	// 	len_flags++;
	// while (i < len_flags)
	// {
	// 	temp = ft_strjoin(temp, str);
	// 	i++;
	// }
	// printf(KRED"flags = [%s]/////////////////////////\n", temp);
	// return (str);
	
	// if (flag->minus == 1)
	// 	flag_minus(str, len_sr);
	// if (flag->padded_zero == 1)
	// 	flag_padded_zero(str, len_str);
	// if (flag->width == 1)
	// 	flag_width(str, len_str);	
	// if (flag->precision == 1)
	// 	flag_precision(str, len_str);