/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:22:44 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/07 14:19:07 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*ans;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
		i++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j < i)
		j++;
	ans = (char *)malloc(sizeof(*ans) * (i - j + 1));
	if (!ans)
		return (0);
	while (j < i)
		ans[k++] = s[j++];
	ans[k] = '\0';
	return (ans);
}
