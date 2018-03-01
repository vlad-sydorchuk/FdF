/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:51:52 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/01 12:06:10 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tmp;

	tmp = dst;
	while (*src && len > 0)
	{
		*tmp++ = *src++;
		len--;
	}
	while (len-- > 0)
		*tmp++ = '\0';
	return (dst);
}
