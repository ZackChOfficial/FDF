/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 21:08:29 by zchatoua          #+#    #+#             */
/*   Updated: 2019/01/20 20:49:55 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(t_global *gl, int i, int j)
{
	gl->t[i][j].collor = gl->color2;
	if (gl->file[i][j] > 0)
		gl->t[i][j].collor = gl->color1;
	if (i < gl->ligne - 1)
		if (gl->file[i + 1][j] > 0)
			gl->t[i][j].collor = gl->color1;
	if (j < gl->collone - 1)
		if (gl->file[i][j + 1] > 0)
			gl->t[i][j].collor = gl->color1;
}

void	put_color(t_global *gl, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, j + x, i + y, color);
			j++;
		}
		i++;
	}
}

void	help(void)
{
	ft_putendl("\033[32mUSAGE: \033[33m ./fdf [your map path]");
	exit(0);
}

void	error(int e)
{
	if (e == 1)
		ft_putstr("\033[31mfile invalide !!\n\033[0m");
	else
		ft_putstr("\033[31minvalid argument!!\n\033[0m");
	exit(0);
}
