/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:51:24 by zchatoua          #+#    #+#             */
/*   Updated: 2019/01/20 20:21:50 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int keycode, t_global *param)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 0 || keycode == 2)
		z(param, keycode);
	else if (keycode == 126 || keycode == 124 ||
			keycode == 125 || keycode == 123)
		move(param, keycode);
	else if (keycode == 35)
		change_projection(param);
	else if (keycode == 69 || keycode == 78)
		scale(param, keycode);
	else if (keycode == 46)
		menu(param);
	else if (keycode == 257)
		(param->vitesse < 2300 / 2) ? param->vitesse += 10 : 1 == 1;
	else if (keycode == 272)
		(param->vitesse >= 10) ? param->vitesse -= 10 : 1 == 1;
	else if (keycode == 47 || keycode == 43)
		change_file(param, keycode);
	return (0);
}

void	change_color(t_global *gl, int x, int y)
{
	if (x >= 50 && x <= 70 && y >= 20 && y <= 40)
		gl->color1 = 0x0000ff;
	else if (x >= 80 && x <= 100 && y >= 20 && y <= 40)
		gl->color1 = 0xffffff;
	else if (x >= 110 && x <= 130 && y >= 20 && y <= 40)
		gl->color1 = 0xe74c3c;
	else if (x >= 140 && x <= 160 && y >= 20 && y <= 40)
		gl->color1 = 0xf1c40f;
	else if (x >= 170 && x <= 190 && y >= 20 && y <= 40)
		gl->color1 = 0x00b16a;
	else if (x >= gl->width - 60 && x <= gl->width - 40 && y >= 20 && y <= 40)
		gl->color2 = 0x0000ff;
	else if (x >= gl->width - 90 && x <= gl->width - 70 && y >= 20 && y <= 40)
		gl->color2 = 0xffffff;
	else if (x >= gl->width - 120 && x <= gl->width - 100 && y >= 20 && y <= 40)
		gl->color2 = 0xe74c3c;
	else if (x >= gl->width - 150 && x <= gl->width - 130 && y >= 20 && y <= 40)
		gl->color2 = 0xf1c40f;
	else if (x >= gl->width - 180 && x <= gl->width - 160 && y >= 20 && y <= 40)
		gl->color2 = 0x00b16a;
}

void	check_line(t_global *gl, int x, int y)
{
	if (gl->check == 1)
	{
		gl->check = 0;
		gl->l2.x = x;
		gl->l2.y = y;
		drawline(*gl, gl->l1, gl->l2, gl->color1);
		gl->l2.x = 0;
		gl->l2.y = 0;
		gl->l1.x = 0;
		gl->l1.y = 0;
	}
	else
	{
		gl->check = 1;
		gl->l1.x = x;
		gl->l1.y = y;
	}
}

int		mouse_press(int keycode, int x, int y, t_global *param)
{
	if (keycode == 4 || keycode == 5)
		z(param, keycode);
	else if (keycode == 1)
		change_projection(param);
	else if (keycode == 3)
	{
		change_color(param, x, y);
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->func(param);
		draw_win(param);
	}
	else if (keycode == 2)
		check_line(param, x, y);
	return (0);
}
