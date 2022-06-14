/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:44:39 by ygeslin           #+#    #+#             */
/*   Updated: 2021/05/12 16:59:46 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int	ft_tnrvfrr(const char *str)
{
	int		i;

	i = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\r' && str[i] != '\f' && str[i] != '\v')
			return (-1);
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int		pos_nb;
	int		sign;
	int		messie;

	pos_nb = ft_tnrvfrr(str);
	messie = 0;
	sign = 1;
	if (pos_nb == -1)
		return (0);
	if (str[pos_nb] == '+' || str[pos_nb] == '-')
	{
		if (str[pos_nb] == '-')
			sign = -sign;
		pos_nb++;
	}
	while (str[pos_nb] >= '0' && str[pos_nb] <= '9')
	{
		messie = (messie * 10) + (str[pos_nb] - '0');
		pos_nb++;
	}
	return (messie * sign);
}

t_uint	get_time(void)
{
	struct timeval	s_time;
	t_uint			time;

	time = (t_uint)gettimeofday(&s_time, NULL);
	time = (t_uint)s_time.tv_sec * 1000 + (t_uint)s_time.tv_usec / 1000;
	return (time);
}

t_uint	get_time_from_start(t_philo *philo)
{
	return (get_time() - philo->start_time);
}

void	wait_for_it(t_philo *philo, t_uint waiting_time)
{
	t_uint	end;

	end = get_time_from_start(philo) + waiting_time;
	while (get_time_from_start(philo) < end)
		usleep(100);
	return ;
}
