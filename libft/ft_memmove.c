/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 11:56:04 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 10:09:13 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*td;
	char	*ts;
	size_t	i;

	td = (char *)dst;
	ts = (char *)src;
	i = -1;
	if (ts > td)
		while (++i < len)
			td[i] = ts[i];
	else
		while (++i < len)
			td[len - i - 1] = ts[len - i - 1];
	return (dst);
}
