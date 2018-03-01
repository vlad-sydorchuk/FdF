/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:19:34 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/03 19:19:40 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*sdup;

	i = 0;
	while (s1[i] != '\0')
		i++;
	sdup = (char *)malloc(1 + i * sizeof(*sdup));
	if (!sdup)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		sdup[i] = s1[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}
