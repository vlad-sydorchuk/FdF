/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:33:06 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 17:01:05 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	k;

	i = -1;
	while (dst[++i] && size != 0)
		size--;
	len = i;
	i = 0;
	while (src[i])
		i++;
	k = len;
	len += i;
	if (size == 0)
		return (len);
	i = -1;
	while (src[++i] && size-- != 1)
		dst[i + k] = src[i];
	dst[i + k] = '\0';
	return (len);
}
