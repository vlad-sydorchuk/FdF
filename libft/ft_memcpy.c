/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:52:32 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/08 16:58:51 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*td;
	char	*ts;

	i = 0;
	td = dst;
	ts = (char *)src;
	while (n != 0)
	{
		td[i] = ts[i];
		i++;
		n--;
	}
	return (dst);
}
