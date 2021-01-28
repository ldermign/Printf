/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:01:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/28 16:04:27 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int		ft_is_flag(const char *str)
{
	if (*str == '-' || *str == '*' || *str == '.'
	|| (*str >= '0' && *str <= '9'))
		return (1);
	return (0);
}

int		ft_check_flag(const char *str)
// verifie si conversion possible, car flag dans bon ordre
// CHECKER D'ABORD TOUTE LA LIGNE
{
	if ((!((*str >= '0' && *str <= '9') || *str == '0' || *str == '-'))
	|| (!(*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
	|| *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X')))
		return (-1);
	str++;
	if (!(*str != '.' || *str != '*' || *str != 'c' || *str != 's' || *str != 'p'
	|| *str != 'd' || *str != 'i' || *str != 'u' || *str != 'x' || *str != 'X'))
		return (-1);
	return (1);
}