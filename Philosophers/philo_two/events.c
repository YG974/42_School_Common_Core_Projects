/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
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
	int	i;

	i = 0;
	sem_wait(philo->print);
	if (g_print_dead == -1 && philo->full[0] != (int)philo->args.philo_nb)
		printf("%6d %d %s\n", get_time_from_start(philo), nb, event);
	else
		i = 0;
	if (event[0] == 'd')
		g_print_dead = 1;
	sem_post(philo->print);
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
	int	i;

	i = 0;
	sem_wait(philo->spoons);
	print(philo, TAKE_FORK, philo->nb);
	if (philo->args.philo_nb == 1)
	{
		wait_for_it(philo, philo->args.tt_die * 2);
		sem_post(philo->spoons);
		return ;
	}
	sem_wait(philo->spoons);
	print(philo, TAKE_FORK, philo->nb);
	sem_wait(philo->eating);
	print(philo, EAT, philo->nb);
	philo->last_meal = get_time_from_start(philo);
	wait_for_it(philo, philo->args.tt_eat);
	sem_post(philo->spoons);
	sem_post(philo->spoons);
	sem_post(philo->eating);
	philo->meals--;
}
