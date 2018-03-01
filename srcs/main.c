/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 14:03:35 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/06 14:03:36 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int		ft_rows(char *filename)
{
	int		fd;
	int		i;
	char	*tmp;
	int		lines;

	tmp = NULL;
	lines = -1;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_err(1);
	while ((i = get_next_line(fd, &tmp)) > 0)
	{
		++lines;
		free(tmp);
	}
	free(tmp);
	close(fd);
	return (++lines);
}

static	int		ft_arrlen(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		;
	return (i);
}

static	int		ft_columns(t_crd ****res, t_dim **dim, char *filename)
{
	int		fd;
	int		flag;
	char	*tmp;
	int		r;
	char	**a;

	r = -1;
	fd = open(filename, O_RDONLY);
	while ((flag = get_next_line(fd, &tmp)) > 0)
	{
		if (flag != 0)
		{
			a = ft_split_cl(tmp, ' ');
			(*dim)->w = (r == -1) ? ft_arrlen(a) : (*dim)->w;
			((*dim)->w != ft_arrlen(a)) ? ft_err(2) : 1;
			if (!((*res)[++r] = (t_crd **)malloc(sizeof(t_crd *) * (*dim)->w)))
				ft_err(3);
			fill_m(&(*res), &a, &(*dim), r);
		}
		ft_free(&a, &tmp);
	}
	free(tmp);
	return (0);
}

static t_crd	***ft_getmap(t_dim **dim, char *filename)
{
	t_crd	***res;

	(*dim)->h = ft_rows(filename);
	if (!(res = (t_crd ***)malloc(sizeof(t_crd **) * (*dim)->h)))
		ft_err(3);
	ft_columns(&res, &(*dim), filename);
	return (res);
}

int				main(int ac, char **av)
{
	t_crd	***map;
	t_dim	*dim;

	if (ac != 2)
		ft_err(0);
	dim = (t_dim *)malloc(sizeof(t_dim));
	map = ft_getmap(&dim, av[1]);
	ft_alg(map, dim);
	return (0);
}
