/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:00:52 by zchatoua          #+#    #+#             */
/*   Updated: 2019/01/20 20:31:07 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	z(t_global *param, int keycode)
{
	if (keycode == 0 || keycode == 4)
	{
		param->z++;
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->func(param);
		draw_win(param);
	}
	else
	{
		param->z--;
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->func(param);
		draw_win(param);
	}
}

void	move(t_global *param, int keycode)
{
	if (keycode == 126)
	{
		param->y -= param->vitesse;
		if (param->collone < 250)
			(param->y < -30) ? param->y = param->height + 30 : 1 == 1;
	}
	else if (keycode == 125)
	{
		param->y += param->vitesse;
		if (param->collone < 250)
			(param->y > param->height) ? param->y = -350 : 1 == 1;
	}
	else if (keycode == 124)
	{
		param->x += param->vitesse;
		(param->x > param->width) ? param->x = -300 : 1 == 1;
	}
	else
	{
		param->x -= param->vitesse;
		(param->x < -30) ? param->x = param->width + 150 : 1 == 1;
	}
	param->func(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_win(param);
}

void	scale(t_global *param, int keycode)
{
	if (keycode == 69)
	{
		if (param->scale < 1000)
		{
			param->scale++;
			mlx_clear_window(param->mlx_ptr, param->win_ptr);
			param->func(param);
			draw_win(param);
		}
	}
	else if (keycode == 78)
	{
		if (param->scale > 0)
		{
			param->scale--;
			mlx_clear_window(param->mlx_ptr, param->win_ptr);
			param->func(param);
			draw_win(param);
		}
	}
}

void	change_projection(t_global *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	if (param->func == fill_cord_iso)
		param->func = fill_cord_conic;
	else if (param->func == fill_cord_conic)
		param->func = fill_parallel;
	else
		param->func = fill_cord_iso;
	param->func(param);
	draw_win(param);
}

void	change_file(t_global *param, int keycode)
{
	if (keycode == 47)
	{
		if (param->i < param->argc)
		{
			param->i++;
			mlx_clear_window(param->mlx_ptr, param->win_ptr);
			init(param);
		}
	}
	else if (keycode == 43)
	{
		if (param->i > 0)
		{
			param->i--;
			mlx_clear_window(param->mlx_ptr, param->win_ptr);
			init(param);
		}
	}
}
