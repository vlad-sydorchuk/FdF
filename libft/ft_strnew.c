/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:07:52 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/09 14:51:40 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*buff;
	size_t	i;

	buff = malloc(size + 1);
	if (!buff)
		return (0);
	i = 0;
	while (i < size)
	{
		buff[i] = 0;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
