/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_width_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:36:41 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/16 22:32:52 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flip_zero_and_space(t_flag_len *flag)
{
	int		i;
	size_t	here;
	size_t	size;
	char	swap;

	i = 0;
	here = 0;
	size = flag->size_final_str_flag;
	while (flag->final_str_flag[here + 1] && (here < flag->size_final_str_flag))
	{
		here++;
		if (flag->final_str_flag[here] != flag->final_str_flag[here + 1])
			break ;
	}
	if (size > here && here > 0)
	{
		size--;
		if (flag->final_str_flag[0] == '-')
			i++;
		if (flag->final_str_flag[size] == '\0')
			size--;
		while (size > here && flag->final_str_flag[size] != '\0')
		{
			swap = flag->final_str_flag[size];
			flag->final_str_flag[size] = flag->final_str_flag[i];
			flag->final_str_flag[i] = swap;
			size--;
			i++;
		}
	}
}

void	width_sup(t_flag_len *flag)
{
	int i;
	int j;
	int max;
	int min;

	i = 0;
	j = 0;
	max = flag->nbr_width;
	min = flag->nbr_precision;
	while (i < (max - min))
	{
		flag->final_str_flag[i] = flag->str_width[i];
		i++;
	}
	while (i < max)
	{
		flag->final_str_flag[i] = flag->str_precision[j];
		i++;
		j++;
	}
	flag->final_str_flag[i] = '\0';
}

void	precision_sup_or_equal_width(t_flag_len *flag)
{
	int i;
	int size;

	i = 0;
	size = flag->nbr_precision;
	while ((i < size))
	{
		flag->final_str_flag[i] = flag->str_precision[i];
		i++;
	}
	flag->final_str_flag[i] = '\0';
}

void	join_str_width_and_precision(int nbr, t_flag_len *flag)
{
	int size;
	
	size = 0;
	if (flag->nbr_precision >= flag->nbr_width)
		size = flag->nbr_precision;
	else if (flag->nbr_precision < flag->nbr_width)
		size = flag->nbr_width;
	if ((flag->final_str_flag = ft_calloc(size + 1, sizeof(char))) == NULL)
		return ;
	if (flag->nbr_precision >= flag->nbr_width)
		precision_sup_or_equal_width(flag);
	else if (flag->nbr_precision < flag->nbr_width)
		width_sup(flag);
	flag->size_final_str_flag = ft_strlen(flag->final_str_flag) + (nbr < 0);
	if (flag->minus == 1)
		flip_zero_and_space(flag);
}