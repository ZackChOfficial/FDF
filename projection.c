/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:51:46 by zchatoua          #+#    #+#             */
/*   Updated: 2019/01/20 20:43:25 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_cord_iso(t_global *gl)
{
	int		i;
	int		j;
	int		prev_x;

	i = 0;
	gl->t = (t_cord **)malloc(sizeof(t_cord *) * gl->ligne);
	while (i < gl->ligne)
	{
		j = 0;
		gl->t[i] = (t_cord *)malloc(sizeof(t_cord ) * gl->collone);
		while (j < gl->collone)
		{
			color(gl, i, j);
			gl->t[i][j].x = j * gl->scale;
			gl->t[i][j].y = i * gl->scale;
			prev_x = gl->t[i][j].y + gl->t[i][j].x;
			gl->t[i][j].x = ((gl->t[i][j].x - gl->t[i][j].y) * cos(0.523599));
			gl->t[i][j].y = (prev_x * sin(0.523599) - (gl->z * gl->file[i][j]));
			gl->t[i][j].x += gl->x;
			gl->t[i][j].y += gl->y;
			j++;
		}
		i++;
	}
}

void	fill_cord_conic(t_global *gl)
{
	int	i;
	int	j;
	int z;

	i = 0;
	gl->t = (t_cord **)malloc(sizeof(t_cord *) * gl->ligne);
	while (i < gl->ligne)
	{
		j = 0;
		gl->t[i] = (t_cord *)malloc(sizeof(t_cord ) * gl->collone);
		while (j < gl->collone)
		{
			color(gl, i, j);
			gl->t[i][j].x = j * gl->scale;
			z = gl->z * gl->file[i][j] + 1;
			gl->t[i][j].y = (i * cos(0.523599)) - (i * sin(0.523599)) * z;
			gl->t[i][j].x += gl->x;
			gl->t[i][j].y += gl->y;
			j++;
		}
		i++;
	}
}

void	fill_parallel(t_global *gl)
{
	int	i;
	int	j;
	int z;

	i = 0;
	gl->t = (t_cord **)malloc(sizeof(t_cord *) * gl->ligne);
	while (i < gl->ligne)
	{
		j = 0;
		gl->t[i] = (t_cord *)malloc(sizeof(t_cord ) * gl->collone);
		while (j < gl->collone)
		{
			color(gl, i, j);
			gl->t[i][j].x = j * gl->scale;
			z = gl->z * gl->file[i][j] * gl->scale;
			gl->t[i][j].y = (i * gl->scale) - z;
			gl->t[i][j].x += gl->x;
			gl->t[i][j].y += gl->y;
			j++;
		}
		i++;
	}
}
