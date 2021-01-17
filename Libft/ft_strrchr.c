/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:15:06 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/12 08:50:13 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t len;

	len = ft_strlen(str);
	if ((char)c == '\0')
		return ((char*)&str[len]);
	while (len > 0)
	{
		len--;
		if (str[len] == (char)c)
			return ((char*)&str[len]);
	}
	return (NULL);
}
