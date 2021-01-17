/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:16:32 by ldermign          #+#    #+#             */
/*   Updated: 2021/01/12 08:51:27 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*dst;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (len_s < start)
	{
		if ((dst = (char*)malloc(sizeof(char) * 1)) == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if ((dst = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_strlcpy(dst, &s[start], len + 1);
	return (dst);
}
