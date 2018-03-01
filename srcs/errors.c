/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 14:04:10 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/06 14:04:11 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_err(int code)
{
	if (code == 0)
		ft_putendl("Usage: ./fdf maps/filiname.fdf");
	else if (code == 1)
		ft_putendl("Problem with file! fd < 0");
	else if (code == 2)
		ft_putendl("File is not valid!");
	else if (code == 3)
		ft_putendl("Problem with malloc!");
	else if (code == 4)
		ft_putendl("Problem with function: fiil_m.");
	exit(0);
}

void	valid(char *s)
{
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (s[++i])
	{
		if ((s[i] >= '0' && s[i] <= '9') ||
			(s[i] >= 'a' && s[i] <= 'f') ||
			(s[i] >= 'A' && s[i] <= 'F') ||
			s[i] == 'x' || s[i] == ',')
			flag = 1;
		else
			ft_err(2);
	}
}

void	ft_free(char ***a, char **tmp)
{
	int		i;

	i = -1;
	while ((*a)[++i])
		free((*a)[i]);
	free(*a);
	free(*tmp);
}
