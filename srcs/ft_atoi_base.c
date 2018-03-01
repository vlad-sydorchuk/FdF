/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 09:26:58 by vsydorch          #+#    #+#             */
/*   Updated: 2017/04/26 14:07:01 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_inbase(char c, int base, char let)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= let && c <= (let + base - 10)));
}

static int	check_case(char *str, int base)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'A' + base)
			return (1);
		if (str[i] >= 'a' && str[i] <= 'a' + base)
			return (0);
	}
	return (1);
}

int			ft_atoi_base(char *str, int base)
{
	int		value;
	int		sign;
	char	letter;

	value = 0;
	if (base < 2 || base > 16)
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = (*str == '-') ? -1 : 1;
	letter = check_case(str, base) ? 'A' : 'a';
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base, letter))
	{
		if (*str - letter >= 0)
			value = value * base + (*str - letter + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * sign);
}
