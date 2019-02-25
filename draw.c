/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdichkou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:54:05 by mdichkou          #+#    #+#             */
/*   Updated: 2019/01/21 12:35:23 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline_low(t_global gl, t_bresn br, int collor)
{
	br.cumul = br.dx / 2;
	br.i = 1;
	while (br.i <= br.dx)
	{
		br.x += br.xinc;
		br.cumul += br.dy;
		if (br.cumul >= br.dx)
		{
			br.cumul -= br.dx;
			br.y += br.yinc;
		}
		mlx_pixel_put(gl.mlx_ptr, gl.win_ptr, br.x, br.y, collor);
		br.i++;
	}
}

void	drawline_high(t_global gl, t_bresn br, int collor)
{
	br.cumul = br.dy / 2;
	br.i = 1;
	while (br.i <= br.dy)
	{
		br.y += br.yinc;
		br.cumul += br.dx;
		if (br.cumul >= br.dy)
		{
			br.cumul -= br.dy;
			br.x += br.xinc;
		}
		mlx_pixel_put(gl.mlx_ptr, gl.win_ptr, br.x, br.y, collor);
		br.i++;
	}
}

void	drawline(t_global gl, t_cord in, t_cord fi, int collor)
{
	t_bresn br;

	br.x = in.x;
	br.y = in.y;
	br.dx = fi.x - in.x;
	br.dy = fi.y - in.y;
	br.xinc = (br.dx > 0) ? 1 : -1;
	br.yinc = (br.dy > 0) ? 1 : -1;
	br.dx = ABS(br.dx);
	br.dy = ABS(br.dy);
	mlx_pixel_put(gl.mlx_ptr, gl.win_ptr, br.x, br.y, collor);
	if (br.dx > br.dy)
		drawline_low(gl, br, collor);
	else
		drawline_high(gl, br, collor);
}

void	draw_color(t_global *gl)
{
	put_color(gl, 50, 20, 0x0000ff);
	put_color(gl, 80, 20, 0xffffff);
	put_color(gl, 110, 20, 0xe74c3c);
	put_color(gl, 140, 20, 0xf1c40f);
	put_color(gl, 170, 20, 0x00b16a);
	put_color(gl, gl->width - 60, 20, 0x0000ff);
	put_color(gl, gl->width - 90, 20, 0xffffff);
	put_color(gl, gl->width - 120, 20, 0xe74c3c);
	put_color(gl, gl->width - 150, 20, 0xf1c40f);
	put_color(gl, gl->width - 180, 20, 0x00b16a);
}

void	draw_win(t_global *gl)
{
	int	i;
	int	j;

	i = 0;
	while (i < gl->ligne)
	{
		j = 0;
		while (j < gl->collone)
		{
			if (j < gl->collone - 1)
				drawline(*gl, gl->t[i][j], gl->t[i][j + 1], gl->t[i][j].collor);
			if (i < gl->ligne - 1)
				drawline(*gl, gl->t[i][j], gl->t[i + 1][j], gl->t[i][j].collor);
			j++;
		}
		i++;
	}
	free(gl->t);
	draw_color(gl);
}
