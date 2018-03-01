/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:49:10 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/01 13:49:18 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s11;
	unsigned char *s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (*s11 == '\0' || *s22 == '\0')
		return (*s11 - *s22);
	while (*s11 && *s22 && *s11 == *s22)
	{
		s11++;
		s22++;
	}
	if (*s11 != *s22)
		return (*s11 - *s22);
	return (0);
}
