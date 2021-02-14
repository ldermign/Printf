/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:46:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 19:36:21 by ldermign         ###   ########.fr       */
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
	// printf("str: [%s], str_of_flag")
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
	while (ft_is_digit(flag->str_of_flag[i]))
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
	if (flag->str_of_flag[i] == '.')
	{
		i++;
		start = i;
		while (ft_is_digit(flag->str_of_flag[i]))
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

void		string_of_flags(va_list ap, t_flag_len *flag)
{
	string_of_flag_to_int(ap, flag);
	if (flag->padded_zero == 1 && flag->nbr_width >= 0 && flag->precision == -1)
	{
		ft_fill_with_c(flag->final_str_flag, '0', flag->nbr_width + 1);
		if ((flag->final_str_flag = malloc(sizeof(char) *
		(flag->nbr_width + 1))) == NULL)
			return ;
	}
	if (flag->width >= 0 && flag->precision)
	{
		flag_width(flag);
		flag_precision(flag);
		if (flag->str_width != NULL && flag->str_precision != NULL)
			join_str_width_and_precision(flag);
	}
	flag->size_final_str_flag = ft_strlen(flag->final_str_flag);
	if (flag->minus == 1)
		flip_zero_and_space(flag);
	if (flag->str_precision != NULL)
		free(flag->str_precision);
	if (flag->str_width != NULL)
		free(flag->str_width);
}

int which_flag(const char *str, t_flag_len *flag)
{
	int avancement;

	avancement = 0;
	ft_init_struct_flag(flag);
	flag->str_of_flag = create_string_of_width_and_precision((char*)str);
	if (*str == '-')
		flag->minus = 1;
	else if (*str == '0' && flag->minus == 0)
		flag->padded_zero = 1;
	while (++str && ft_is_flag(*str))
	{
		if (*str == '*' || ft_is_digit(*str) || *str == '.')
		{
			flag->width = 1;
			while ((*str == '*' || ft_is_digit(*str)) && str++)
				avancement++;
			if (*str == '.' && (ft_is_digit(*(str + 1))
			|| *(str + 1) == '*'))
				flag->precision = 1;
		}
		avancement++;
	}
	return (avancement);
}

int		ft_check_flag(const char *str)
{
	str++;
	if (!ft_is_all(*str))
		return (-1);
	while (ft_is_all(*str))
	{
		if (ft_is_digit(*str) && *(str + 1) == '*')
			return (-1);
		if (*str == '*' && ft_is_digit(*(str + 1)))
			return (-1);
		str++;
	}
	return (1);
}
