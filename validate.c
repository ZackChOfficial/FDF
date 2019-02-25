/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:36:46 by zchatoua          #+#    #+#             */
/*   Updated: 2019/01/21 11:53:07 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		first_line(t_global *gl, char *line, int fd)
{
	char	**t;
	int		i;

	if (fd < 1)
		error(1);
	get_next_line(fd, &line);
	t = ft_strsplit(line, ' ');
	i = 0;
	while (t[i])
		i++;
	free(line);
	free(t);
	gl->collone = i;
	return (i);
}

void	validate(t_global *gl)
{
	int		j;
	int		i;
	char	**t;
	char	*line;

	line = NULL;
	if (gl->fd)
	{
		free(gl->file);
		close(gl->fd);
	}
	gl->fd = open(gl->files[gl->i], O_RDONLY);
	if ((i = first_line(gl, line, gl->fd)) == -1)
		return ;
	while (get_next_line(gl->fd, &line))
	{
		t = ft_strsplit(line, ' ');
		gl->ligne++;
		free(line);
		j = 0;
		while (t[j])
			j++;
		free(t);
		(j != i) ? error(1) : 1 == 1;
	}
}
