/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:21:19 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/19 14:56:01 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*get_fd(const int fd, t_gnl **lst)
{
	t_gnl	*curr;

	if (fd < 0 || BUFF_SIZE < 1)
		return (NULL);
	curr = *lst;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	if (!(curr = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	curr->fd = fd;
	curr->content = ft_strnew(BUFF_SIZE + 1);
	ft_bzero(curr->content, BUFF_SIZE);
	curr->next = *lst;
	*lst = curr;
	return (curr);
}

static int		check_content(t_gnl *file, char **line)
{
	char *str;

	str = ft_strchr(file->content, '\n');
	if (str != NULL)
	{
		*line = ft_strsub(file->content, 0, ft_count(file->content, *str));
		ft_strcpy(file->content, (str + 1));
		return (1);
	}
	if (file->content != '\0')
	{
		*line = ft_strdup(file->content);
		ft_bzero(file->content, ft_strlen(file->content));
	}
	return (0);
}

static int		end_of_line(t_gnl *file, char **line, char *str, char *buff)
{
	char	*tmp;

	tmp = ft_strsub(buff, 0, ft_count(buff, *str));
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	if (!(tmp = ft_strdup(file->content)))
		return (-1);
	ft_bzero(file->content, ft_strlen(file->content));
	file->content = ft_strjoin(tmp, str + 1);
	free(tmp);
	str = NULL;
	return (1);
}

static int		check_error(t_gnl *file, char **line)
{
	if (!file || !line)
		return (-1);
	if (check_content(file, line))
		return (1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*lst;
	int				ret;
	t_gnl			*file;
	char			*str;
	char			buff[BUFF_SIZE + 1];

	file = get_fd(fd, &lst);
	if ((ret = check_error(file, line)))
		return (ret);
	while ((ret = read(file->fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		str = ft_strchr(buff, '\n');
		if (str != NULL)
			return (end_of_line(file, line, str, buff));
		str = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(str, buff);
		free(str);
	}
	if (**line != '\0')
		return (1);
	return (0);
}
