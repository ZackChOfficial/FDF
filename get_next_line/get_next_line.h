/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:42:55 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/17 10:40:05 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# define BUFF_SIZE 1000

typedef struct		s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}					t_gnl;
int					get_next_line(const int fd, char **line);
#endif
