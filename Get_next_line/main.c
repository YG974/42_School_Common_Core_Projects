/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <ygeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:12:40 by ygeslin           #+#    #+#             */
/*   Updated: 2022/06/13 16:41:49 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
	char **ptr;
	char *str;
	str = NULL;
	int fd = open("test.txt", O_RDONLY);
	ptr = &str;
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	fd = open("test2.txt", O_RDONLY);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	fd = 3;
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	printf("fd : %d ->%d%s\n", fd, get_next_line(fd, &str), str);
	return (0);
}
