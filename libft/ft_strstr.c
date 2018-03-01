/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:11:06 by vsydorch          #+#    #+#             */
/*   Updated: 2016/12/01 11:25:05 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int k;
	int j;
	int len;

	i = 0;
	len = 0;
	while (little[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)&big[i]);
	while (big[i] != '\0')
	{
		j = i;
		k = 0;
		while (big[j] && big[j] == little[k])
		{
			j++;
			k++;
			if (k == len)
				return ((char *)&big[j - len]);
		}
		i++;
	}
	return (0);
}
