/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:04:00 by ygeslin           #+#    #+#             */
/*   Updated: 2019/11/21 15:12:54 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define ENDL '\n'
# define END '\0'
# define NB_FD 256
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define MALLCHECK(x) if (!x) return (-1);

typedef struct	s_gnl
{
	int				ret;
	int				i;
	int				j;
}				t_gnl;

int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
char			*ft_strjoin_endl(char *s1, const char *s2);
int				ft_strchr(const char *s, int c);
char			*ft_strjoin(char *s1, const char *s2);
int				ft_next_line(int i, int fd, char gnl[NB_FD][BUFFER_SIZE + 1]);

#endif
