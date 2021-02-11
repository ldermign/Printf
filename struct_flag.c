/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/11 14:53:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_flag(char *str, va_list ap, t_flag_len *flag)
{
	(void)ap;
	(void)flag;
	int len_flag;
//	char *str_flag;
	int i;

	i = 0;
	len_flag = 0;
	str--;
/*	while (ft_is_all(*str) && str--)
		len_flag++;
	while ((i < len_flag) && i++)
		str++;
	printf("len_flag = %d\n", len_flag);
	str_flag = ft_rev_string(str, len_flag);
	printf(KRED"flags = [%s]\n", str);*/
	return (str);
}

	//return (char*)(str);
	/*char *temp;
	int i = 0;
	int len_flags = 0;
	while (ft_is_flag(*str))
		len_flags++;
	while (i < len_flags)
	{
		temp = ft_strjoin(temp, str);
		i++;
	}
	printf(KRED"flags = [%s]/////////////////////////\n", temp);
	return (str);
	
	if (flag->minus == 1)
		flag_minus(str, len_sr);
	if (flag->padded_zero == 1)
		flag_padded_zero(str, len_str);
	if (flag->width == 1)
		flag_width(str, len_str);	
	if (flag->precision == 1)
		flag_precision(str, len_str);
	*/

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
	if (str)
	{
		while (ft_is_flag(*str))
		{
			if (*str == '-')
				flag->minus = 1;
			if (*str == '0')
				flag->padded_zero = 1;
			if (*str == '*' || (ft_is_digit(*str) && *(str + 1) == '.'))
			{
				flag->width = 1;
				while (*str == '*' || ft_is_digit(*str))
					str++;
				if ((*str == '.' && ft_is_digit(*str + 1))
				|| *(str + 1) == '*')
					flag->precision = 1;
			}
			str++;
		}
	}
	avancement -= ft_strlen((str) - 1);
	return (avancement);
}

int		ft_check_flag(const char *str, t_flag_len *flag)
{
	str++;
	if (flag->minus == 1 && flag->padded_zero == 1)
		flag->padded_zero = 0;
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