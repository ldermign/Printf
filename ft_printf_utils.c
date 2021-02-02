/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 09:19:29 by ldermign          #+#    #+#             */
/*   Updated: 2021/02/02 13:45:01 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_struct *ntm)
{
	write(1, &c, 1);
	ntm->final_len++;
}

void	ft_putstr(char *str, t_struct *ntm)
{
	size_t len;

	if (!str)
		return ;
	len = ft_strlen(str);
	write(1, str, len);
	ntm->final_len += (int)len;
}