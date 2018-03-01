/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsydorch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:00:42 by vsydorch          #+#    #+#             */
/*   Updated: 2017/05/10 13:05:33 by vsydorch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	dr_inf(t_gr *mlx)
{
	mlx_string_put(mlx->init, mlx->win, 45, 250, 0x71ABEC,
			" Left -> Press \'D\'");
	mlx_string_put(mlx->init, mlx->win, 30, 280, 0x71ECAB,
			"Zoom (numpad): ");
	mlx_string_put(mlx->init, mlx->win, 45, 300, 0x71ABEC,
			"Zoom++ -> Press \'+\'");
	mlx_string_put(mlx->init, mlx->win, 45, 320, 0x71ABEC,
			"Zoom-- -> Press \'-\'");
	mlx_string_put(mlx->init, mlx->win, 30, 350, 0x71ECAB,
			"Rotation (numpad): ");
	mlx_string_put(mlx->init, mlx->win, 45, 370, 0x71ABEC,
			"X++ -> Press \'7\'");
	mlx_string_put(mlx->init, mlx->win, 45, 390, 0x71ABEC,
			"X-- -> Press \'8\'");
	mlx_string_put(mlx->init, mlx->win, 45, 410, 0x71ABEC,
			"Y++ -> Press \'4\'");
	mlx_string_put(mlx->init, mlx->win, 45, 430, 0x71ABEC,
			"Y-- -> Press \'5\'");
	mlx_string_put(mlx->init, mlx->win, 30, 500, 0xECA971,
			"Exit -> Press \"ESC\"");
}

void			draw_info(t_gr *mlx)
{
	mlx_string_put(mlx->init, mlx->win, 30, 30, 0x71ECAB,
			"Projections:");
	mlx_string_put(mlx->init, mlx->win, 45, 50, 0x71ABEC,
			"Isometric -> Press \'I\'");
	mlx_string_put(mlx->init, mlx->win, 45, 70, 0x71ABEC,
			" Parallel -> Press \'P\'");
	mlx_string_put(mlx->init, mlx->win, 30, 100, 0x71ECAB,
			"Change \'Z\':");
	mlx_string_put(mlx->init, mlx->win, 45, 120, 0x71ABEC,
			"Z++ -> Press \'X\'");
	mlx_string_put(mlx->init, mlx->win, 45, 140, 0x71ABEC,
			"Z-- -> Press \'Z\'");
	mlx_string_put(mlx->init, mlx->win, 30, 170, 0x71ECAB,
			"Move figure: ");
	mlx_string_put(mlx->init, mlx->win, 45, 190, 0x71ABEC,
			"   Up -> Press \'W\'");
	mlx_string_put(mlx->init, mlx->win, 45, 210, 0x71ABEC,
			" Down -> Press \'S\'");
	mlx_string_put(mlx->init, mlx->win, 45, 230, 0x71ABEC,
			"Right -> Press \'A\'");
	dr_inf(mlx);
}

void			ft_alg(t_crd ***map, t_dim *dim)
{
	t_all	*all;
	t_gr	*mlx;
	t_crd	***res;

	mlx = (t_gr *)malloc(sizeof(t_gr));
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WW, WH, "FDF");
	all = (t_all *)malloc(sizeof(t_all));
	all->dim = dim;
	all->mlx = mlx;
	all->m = map;
	all->flag = 5;
	all->step = 5;
	res = ft_isometric(map, dim);
	all->r = res;
	mlx_hook(mlx->win, 2, 5, ft_hooks, all);
	draw_info(all->mlx);
	mlx_loop(mlx->init);
}
