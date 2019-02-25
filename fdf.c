/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdichkou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:40:36 by mdichkou          #+#    #+#             */
/*   Updated: 2019/01/20 20:24:56 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_file(t_global *gl)
{
	int		i;
	int		j;
	char	**tmp;
	char	*str;

	if (gl->fd)
		close(gl->fd);
	gl->fd = open(gl->files[gl->i], O_RDONLY);
	gl->file = (int **)malloc(sizeof(int *) * gl->ligne);
	i = 0;
	while (get_next_line(gl->fd, &str) != 0)
	{
		j = 0;
		tmp = ft_strsplit(str, ' ');
		gl->file[i] = (int *)malloc(sizeof(int) * gl->collone);
		while (tmp[j] != 0)
		{
			gl->file[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		i++;
		free(tmp);
		free(str);
	}
}
