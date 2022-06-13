/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:01:41 by ygeslin           #+#    #+#             */
/*   Updated: 2019/11/21 16:41:40 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		gnl[NB_FD][BUFFER_SIZE + 1] = {{'\0'}};
	t_gnl			s;

	s.j = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || (s.i = read(fd, gnl[fd], 0)))
		return (-1);
	MALLCHECK((*line = (char *)malloc(sizeof(char) * 1)));
	*line[0] = END;
	if ((s.i = ft_strchr(gnl[fd], ENDL)) > -1)
	{
		MALLCHECK((*line = ft_strjoin_endl(*line, gnl[fd])));
		while (s.i + s.j < BUFFER_SIZE)
			return (ft_next_line(s.i, fd, &*gnl));
	}
	MALLCHECK((*line = ft_strjoin(*line, gnl[fd])));
	while ((s.ret = read(fd, gnl[fd], BUFFER_SIZE)) > 0)
	{
		gnl[fd][s.ret] = END;
		MALLCHECK((*line = ft_strjoin_endl(*line, gnl[fd])));
		if ((s.i = ft_strchr(gnl[fd], ENDL)) > -1)
			return (ft_next_line(s.i, fd, &*gnl));
	}
	gnl[fd][0] = '\0';
	return (0);
}

int	ft_next_line(int i, int fd, char gnl[NB_FD][BUFFER_SIZE + 1])
{
	int j;

	j = 0;
	while (i + j < BUFFER_SIZE)
	{
		gnl[fd][j] = gnl[fd][i + j + 1];
		j++;
	}
	return (1);
}
