/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:16:58 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/07 16:16:59 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void		ft_z(int key, t_all *all)
{
	int		r;
	int		c;

	r = -1;
	while (++r < all->dim->h)
	{
		c = -1;
		while (++c < all->dim->w)
		{
			if (all->m[r][c]->z != 0)
			{
				if (key == Z)
					if ((all->m[r][c]->z = all->m[r][c]->z - 0.1) == 0)
						all->m[r][c]->z = all->m[r][c]->z - 0.1;
				if (key == X)
					if ((all->m[r][c]->z = all->m[r][c]->z + 0.1) == 0)
						all->m[r][c]->z = all->m[r][c]->z + 0.1;
			}
		}
	}
	all->r = (all->flag) ? ft_isometric(all->m, all->dim)
		: ft_parallel(all->m, all->dim);
	ft_drw(all->r, all->dim, all->mlx, all);
}

static	void		ft_disp(t_all *all, int flag)
{
	int i;
	int j;

	i = -1;
	while (++i < all->dim->h)
	{
		j = -1;
		while (++j < all->dim->w)
		{
			if (flag == 1)
				all->r[i][j]->y += all->step;
			if (flag == 2)
				all->r[i][j]->y -= all->step;
			if (flag == 3)
				all->r[i][j]->x += all->step;
			if (flag == 4)
				all->r[i][j]->x -= all->step;
		}
	}
	ft_drw(all->r, all->dim, all->mlx, all);
}

static	void		ft_zoom(int key, t_all *all)
{
	if (key == ZMP && all->dim->zm <= 38)
		all->dim->zm += all->dim->st;
	if (key == ZMM && all->dim->zm > 1)
		all->dim->zm -= all->dim->st;
	all->r = (all->flag) ? ft_isometric(all->m, all->dim)
		: ft_parallel(all->m, all->dim);
	ft_drw(all->r, all->dim, all->mlx, all);
}

static	void		ft_rot(int key, t_all *all)
{
	all->dim->al += (key == XPL) ? 3 : 0;
	all->dim->al -= (key == XMN) ? 3 : 0;
	all->dim->p += (key == YPL) ? 3 : 0;
	all->dim->p -= (key == YMN) ? 3 : 0;
	all->r = (all->flag) ? ft_isometric(all->m, all->dim)
		: ft_parallel(all->m, all->dim);
	ft_drw(all->r, all->dim, all->mlx, all);
}

int					ft_hooks(int key, t_all *all)
{
	(key == ESC) ? exit(0) : 0;
	(key == I || key == P) ? ft_prj(key, all) : 0;
	((key == ZMP || key == ZMM) && all->flag != 5) ? ft_zoom(key, all) : 0;
	(key == YP) ? ft_disp(all, 1) : 0;
	(key == YM) ? ft_disp(all, 2) : 0;
	(key == XP) ? ft_disp(all, 3) : 0;
	(key == XM) ? ft_disp(all, 4) : 0;
	((key == Z || key == X) && all->flag != 5) ? ft_z(key, all) : 0;
	(key == XPL || key == XMN || key == YPL || key == YMN) ?
			ft_rot(key, all) : 0;
	return (0);
}
