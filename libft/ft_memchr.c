/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:22:08 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 12:12:03 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	tc;
	int				i;

	tmp = (unsigned char *)s;
	tc = (unsigned char)c;
	i = 0;
	while (n != 0)
	{
		if (tmp[i] == tc)
			return (&tmp[i]);
		i++;
		n--;
	}
	return (0);
}
