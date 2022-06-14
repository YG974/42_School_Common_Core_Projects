/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <ygeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:44:39 by ygeslin           #+#    #+#             */
/*   Updated: 2022/05/03 15:03:15 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

void	join_threads(t_philo *th)
{
	int	i;

	i = -1;
	while (++i < (int)th[0].args.philo_nb)
	{
		pthread_join(th[i].monitor_nb, NULL);
		pthread_join(th[i].thread_nb, NULL);
	}
}

void	print(t_philo *philo, char *event, int nb)
{
	// int	i;

	// i = 0;
	pthread_mutex_lock(philo->print);
	if (g_print_dead == -1 && philo->full[0] != (int)philo->args.philo_nb)
		printf("%6d %d %s\n", get_time_from_start(philo), nb, event);
	// else
		// i = 0;
	if (event[0] == 'd')
		g_print_dead = 1;
	pthread_mutex_unlock(philo->print);
}

void	philo_think(t_philo *philo)
{
	print(philo, THINK, philo->nb);
}

void	philo_sleep(t_philo *philo)
{
	print(philo, SLEEP, philo->nb);
	wait_for_it(philo, philo->args.tt_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->spoon_left);
	print(philo, TAKE_FORK, philo->nb);
	if (philo->args.philo_nb == 1)
	{
		wait_for_it(philo, philo->args.tt_die * 2);
		pthread_mutex_unlock(philo->spoon_left);
		return ;
	}
	pthread_mutex_lock(philo->spoon_right);
	print(philo, TAKE_FORK, philo->nb);
	pthread_mutex_lock(&philo->eating[philo->nb - 1]);
	print(philo, EAT, philo->nb);
	philo->last_meal = get_time_from_start(philo);
	wait_for_it(philo, philo->args.tt_eat);
	pthread_mutex_unlock(philo->spoon_left);
	pthread_mutex_unlock(philo->spoon_right);
	pthread_mutex_unlock(&philo->eating[philo->nb - 1]);
	philo->meals--;
}
