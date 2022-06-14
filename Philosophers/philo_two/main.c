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

void	*routine_monitor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (1)
	{
		sem_wait(philo->eating);
		if (get_time_from_start(philo) - philo->last_meal > philo->args.tt_die)
			philo->dead[0] = (int)philo->nb;
		sem_post(philo->eating);
		if (philo->dead[0] > 0 || philo->meals == 0 || g_print_dead != -1)
			break ;
		wait_for_it(philo, 2);
	}
	return (NULL);
}

void	*routine_philo(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->meals == -1)
		philo->meals = 2147483647;
	philo->last_meal = get_time_from_start(philo);
	while (philo->meals > 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (g_print_dead != -1)
			break ;
	}
	philo->full[0]++;
	return (NULL);
}

void	philo_master_monitor_main(t_philo *philo)
{
	int		nb;

	nb = 0;
	while (1)
	{
		if (philo->dead[0] > 0)
		{
			nb = philo->dead[0];
			print(philo, DIED, nb);
			return ;
		}
		if (g_print_dead != -1)
			break ;
		if (philo->full[0] == (int)philo->args.philo_nb)
			break ;
	}
	return ;
}

int	destroy_all(t_philo *th)
{
	sem_unlink(SEM_EATING);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_SPOONS);
	sem_close(th->spoons);
	sem_close(th->eating);
	sem_close(th->print);
	free((void *)th);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 5)
		return (printf("%s\n", ERR_MISSING_ARGS));
	else if (ac > 6)
		return (printf("%s\n", ERR_TO_MANY_ARGS));
	if (parse_input(ac, av) < 0)
		return (-1);
	return (1);
}
