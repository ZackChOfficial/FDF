/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:35:32 by zchatoua          #+#    #+#             */
/*   Updated: 2019/01/20 20:39:23 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_str(t_global *gl)
{
	mlx_string_put(gl->menu_ptr, gl->menu_win, 200, 20, 0xffffff,
			"How To Use");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 90, 0xffffff,
			"zoom in:           (+)");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 130, 0xffffff,
			"zoom out:          (-)");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 170, 0xffffff,
			"move:              < ^ >");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 210, 0xffffff,
			"up z value:        (a  or scroll up)");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 250, 0xffffff,
			"down z value:      (d or scroll down)");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 290, 0xffffff,
			"change projection: (p or left mouse button)");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 330, 0xffffff,
			"increase vitesse:  (shift button)");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 370, 0xffffff,
			"decrease vitesse:  (uplock button)");
	mlx_string_put(gl->menu_ptr, gl->menu_win, 10, 410, 0xffffff,
			"close program:     (esc button)");
}

void	how_to_use(t_global *gl)
{
	int i;
	int j;

	i = 0;
	while (i < 70)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(gl->menu_ptr, gl->menu_win, j, i, 0x00b16a);
			j++;
		}
		i++;
	}
	put_str(gl);
}

void	menu(t_global *gl)
{
	gl->menu_ptr = mlx_init();
	gl->menu_win = mlx_new_window(gl->menu_ptr, 500, 650, "menu 42");
	how_to_use(gl);
	mlx_loop(gl->menu_ptr);
}
