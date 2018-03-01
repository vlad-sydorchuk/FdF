/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:09:24 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/06 10:11:34 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*buff;
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	buff = malloc(size);
	if (!buff)
		return (0);
	while (i < size)
	{
		*((unsigned char*)(buff + i)) = 0;
		i++;
	}
	return (buff);
}
