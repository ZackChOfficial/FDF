/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdichkou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:46:50 by mdichkou          #+#    #+#             */
/*   Updated: 2019/01/20 20:35:07 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_global *gl)
{
	gl->y = gl->height / 2 - 300;
	gl->ligne = 1;
	gl->func = fill_cord_iso;
	gl->vitesse = 10;
	validate(gl);
	if (gl->collone <= 200)
	{
		gl->scale = 400 / gl->collone;
		gl->z = 100 / gl->collone;
	}
	else
	{
		gl->scale = 1;
		gl->z = 1;
	}
	fill_file(gl);
	gl->x = gl->width / 2 - (gl->collone * gl->scale) / 2;
	fill_cord_iso(gl);
	draw_win(gl);
	mlx_hook(gl->win_ptr, 2, 0, key_press, gl);
	mlx_hook(gl->win_ptr, 4, 0, mouse_press, gl);
	mlx_loop(gl->mlx_ptr);
}

void	initial(t_global *gl, int argc)
{
	gl->i = 0;
	gl->fd = 0;
	gl->width = 2600;
	gl->height = 1300;
	gl->argc = argc - 2;
	gl->color1 = 0x00ffff;
	gl->color2 = 0xffffff;
	gl->mlx_ptr = mlx_init();
	gl->win_ptr = mlx_new_window(gl->mlx_ptr, gl->width, gl->height, "1337");
	gl->files = (char **)malloc(sizeof(char *) * (argc - 1));
}

int		main(int argc, char **argv)
{
	t_global	gl;
	int			i;

	if (argc < 2 || argc > 10)
		error(2);
	else
	{
		if (ft_strcmp(argv[1], "--help") == 0)
			help();
		i = 1;
		initial(&gl, argc);
		while (i < argc)
		{
			gl.files[i - 1] = ft_strdup(argv[i]);
			i++;
		}
		init(&gl);
	}
	return (0);
}
