/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/17 11:42:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct_flag(t_flag_len *flag)
{
	flag->minus = 0;
	flag->padded_zero = 0;
	flag->width = -1;
	flag->precision = -1;
	flag->nbr_width = 0;
	flag->nbr_precision = 0;
	flag->str_of_flag = NULL;
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

char	*create_string_of_width_and_precision(char *str)
{
	int		i;
	int		start;
	int		len_flag;
	char	*str_of_flag;

	i = 0;
	start = 0;
	len_flag = 0;
	if (str[i] == '0' || str[i] == '-')
	{
		i++;
		start++;
	}
	while (ft_is_flag(str[i]))
	{
		i++;
		len_flag++;
	}
	if ((str_of_flag = ft_calloc((len_flag + 1), sizeof(char))) == NULL)
		return (NULL);
	i = start;
	str_of_flag = ft_strncat(str_of_flag, &str[i], len_flag);
	return (str_of_flag);
}

void	string_of_flag_to_int(va_list ap, t_flag_len *flag)
{
	int		i;
	int		start;
	int		len_int;
	char	*temp;

	i = 0;
	start = 0;
	len_int = 0;
	while (flag->str_of_flag[i] && ft_is_digit(flag->str_of_flag[i]))
	{
		len_int++;
		i++;
	}
	if (len_int > 0)
	{
		if ((temp = ft_calloc(len_int + 1, sizeof(char))) == NULL)
			return ;
		ft_strcat(temp, &flag->str_of_flag[start]);
		flag->nbr_width = ft_atoi_printf(temp);
		free(temp);
	}
	if (flag->str_of_flag[i] == '*')
		flag->nbr_width = va_arg(ap, int);
	if (flag->nbr_width < 0)
	{
		flag->nbr_width *= -1;
		flag->minus = 1;
	}
	i++;
	if (flag->str_of_flag[i] && flag->str_of_flag[i] == '.')
	{
		i++;
		start = i;
		while (flag->str_of_flag[i] && ft_is_digit(flag->str_of_flag[i]))
		{
			len_int++;
			i++;
		}
		if (len_int > 0)
		{
			if ((temp = ft_calloc(len_int + 1, sizeof(char))) == NULL)
				return ;
			ft_strcat(temp, &flag->str_of_flag[start]);
			flag->nbr_precision = ft_atoi_printf(temp);
			free(temp);
		}
		if (flag->str_of_flag[i] == '*')
			flag->nbr_precision = va_arg(ap, int);
	}
}

int		which_flag(const char *str, t_flag_len *flag)
{
	int avancement;

	avancement = 0;
	ft_init_struct_flag(flag);
	flag->str_of_flag = create_string_of_width_and_precision((char*)str);
	if (*str == '-' && ++str)
		flag->minus = 1;
	else if (*str == '0' && flag->minus == 0 && ++str)
		flag->padded_zero = 1;
	if (flag->minus == 1 || flag->padded_zero == 1)
		avancement++;
	while (ft_is_flag(*str) && str++)
	{
		if (*str == '*' || ft_is_digit(*str))
			flag->width = 1;
		while ((*str == '*' || ft_is_digit(*str)) && str++)
			avancement++;
		if (*str == '.' && (ft_is_digit(*(str + 1)) || *(str + 1) == '*'))
			flag->precision = 1;
		++avancement;
	}
	return (avancement);
}
