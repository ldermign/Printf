/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_width_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 09:36:41 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/14 09:48:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	precision_sup(t_flag_len *flag)
{
	int i;
	int j;
	int max;
	int min;

	i = 0;
	j = 0;
	max = flag->nbr_precision;
	min = flag->nbr_width;
	while (i <= (max - min))
	{
		flag->final_str_flag[i] = flag->str_precision[i];
		i++;
	}
	while (i < max)
	{
		flag->final_str_flag[i] = flag->str_width[j];
		i++;
		j++;
	}
	flag->final_str_flag[i] = '\0';
}

void	precision_and_width_equal(t_flag_len *flag)
{
	int i;
	int size;

	i = 0;
	size = flag->nbr_precision;
	while (i < size)
	{
		flag->final_str_flag[i] = flag->str_precision[i];
		i++;
	}
	flag->final_str_flag[i] = '\0';
}

void	join_str_width_and_precision(t_flag_len *flag)
{
	int size;
	
	if (flag->nbr_precision >= flag->nbr_width)
		size = flag->nbr_precision;
	else
		size = flag->nbr_width;
	if ((flag->final_str_flag = malloc(sizeof(char) * (size + 1))) == NULL)
		return ;
	if (flag->nbr_precision >= flag->nbr_width)
		precision_and_width_equal(flag);
	else
		width_sup(flag);
}

void	flip_zero_and_space(t_flag_len *flag)
{
	int		i;
	int		here;
	int		size_str;
	char	*swap;

	i = 0;
	here = 0;
	size_str = ft_strlen(flag->final_str_flag);
	swap = NULL;
	while (flag->final_str_flag[here + 1] && (flag->final_str_flag[here]
	== flag->final_str_flag[here + 1]))
		here++;
	if (here > 0)
	{
		while (here > 0)
		{
			*swap = flag->final_str_flag[size_str];
			flag->final_str_flag[size_str] = flag->final_str_flag[i];
			flag->final_str_flag[i] = *swap;
			size_str--;
			i++;
		}
	}
}