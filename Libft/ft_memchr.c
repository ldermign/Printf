/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 23:09:33 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/12 08:44:42 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	size_t			n_bytes;
	unsigned char	*s;

	i = 0;
	n_bytes = n;
	s = (unsigned char*)str;
	while (n_bytes > 0)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		n_bytes--;
		i++;
	}
	return (NULL);
}
