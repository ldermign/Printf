/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:11:24 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/05 08:48:19 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int		i;
	char	*s;
	size_t	len_bytes;

	i = 0;
	s = str;
	len_bytes = len;
	while (len_bytes > 0)
	{
		s[i] = (unsigned char)c;
		i++;
		len_bytes--;
	}
	return (str);
}
