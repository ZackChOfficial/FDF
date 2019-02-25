/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:30:47 by zchatoua          #+#    #+#             */
/*   Updated: 2019/01/21 12:34:13 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# define ABS(x) x <= 0 ? (-x):x

typedef	struct	s_cord
{
	int			x;
	int			y;
	int			collor;
}				t_cord;

typedef	struct	s_global
{
	t_cord		**t;
	int			**file;
	char		**files;
	void		*mlx_ptr;
	void		*menu_ptr;
	void		*menu_win;
	void		*win_ptr;
	int			width;
	int			height;
	int			ligne;
	int			argc;
	int			collone;
	void		(*func)(struct s_global *gl);
	int			scale;
	int			vitesse;
	int			color1;
	int			color2;
	int			x;
	int			y;
	int			fd;
	int			check;
	t_cord		l1;
	t_cord		l2;
	int			i;
	int			z;
}				t_global;

typedef	struct	s_bresn
{
	int			dx;
	int			dy;
	int			i;
	int			xinc;
	int			yinc;
	int			cumul;
	int			x;
	int			y;
}				t_bresn;

void			drawline(t_global gl, t_cord in, t_cord fi, int collor);
void			fill_file(t_global *gl);
void			fill_cord_iso(t_global *gl);
void			fill_parallel(t_global *gl);
void			fill_cord_conic(t_global *gl);
int				key_press(int keycode, t_global *param);
void			draw_win(t_global *gl);
int				mouse_press(int keycode, int x, int y, t_global *param);
void			rotate_x(t_global *gl);
void			menu(t_global *gl);
void			init(t_global *gl);
void			validate(t_global *gl);
void			z(t_global *param, int keycode);
void			move(t_global *param, int keycode);
void			scale(t_global *param, int keycode);
void			change_projection(t_global *param);
void			change_file(t_global *param, int keycode);
void			color(t_global *gl, int i, int j);
void			put_color(t_global *gl, int x, int y, int color);
void			help(void);
void			error(int e);
#endif
