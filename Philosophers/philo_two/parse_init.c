/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
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
#include <sys/fcntl.h>
#include <sys/select.h>
#include <unistd.h>

void	init_threads_philo(t_philo *th)
{
	int			i;

	i = 0;
	while (i < (int)th[0].args.philo_nb)
	{
		pthread_create(&th[i].thread_nb, NULL, &routine_philo, &th[i]);
		pthread_create(&th[i].monitor_nb, NULL, &routine_monitor, &th[i]);
		i = i + 2;
		usleep(100);
	}
	i = 1;
	while (i < (int)th[0].args.philo_nb)
	{
		pthread_create(&th[i].thread_nb, NULL, &routine_philo, &th[i]);
		pthread_create(&th[i].monitor_nb, NULL, &routine_monitor, &th[i]);
		i = i + 2;
		usleep(100);
	}
	philo_master_monitor_main(&th[0]);
	join_threads(th);
	if (!(destroy_all(th)))
		return ;
	return ;
}

int	init_philo(t_philo philo)
{
	t_philo		*all;
	int			i;

	all = (t_philo *)malloc(sizeof(t_philo) * philo.args.philo_nb);
	if (!(all))
		return (-printf("%s\n", ERR_MALLOC));
	i = -1;
	while (++i < (int)philo.args.philo_nb)
	{
		all[i] = philo;
		all[i].nb = (t_uint)i + 1;
	}
	init_threads_philo(all);
	return (1);
}

int	parse_error(t_philo *philo)
{
	if (philo->args.philo_nb < 1 || philo->args.philo_nb > 200)
		return (-printf("%s\n", ERR_PHILO));
	if (philo->args.tt_die < 60 || philo->args.tt_eat < 60
		|| philo->args.tt_sleep < 60)
		return (-printf("%s\n", ERR_TIME_TO));
	return (1);
}

int	init_philo_data(t_philo *philo)
{
	int			dead_bool;
	int			philo_full_nb;

	philo_full_nb = 0;
	dead_bool = -1;
	philo->meals = philo->args.meal_nb;
	philo->start_time = get_time();
	philo->last_meal = get_time_from_start(philo);
	philo->full = &philo_full_nb;
	sem_unlink(SEM_EATING);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_SPOONS);
	sem_close(philo->spoons);
	sem_close(philo->eating);
	sem_close(philo->print);
	philo->eating = sem_open(SEM_EATING, O_CREAT | O_EXCL, S_IRWXG,
			philo->args.philo_nb / 2 + 1);
	philo->spoons = sem_open(SEM_SPOONS, O_CREAT | O_EXCL, S_IRWXG,
			philo->args.philo_nb);
	philo->print = sem_open(SEM_PRINT, O_CREAT | O_EXCL, S_IRWXG, 1);
	philo->dead = &dead_bool;
	g_print_dead = -1;
	if (!init_philo(*philo))
		return (-1);
	return (1);
}

int	parse_input(int ac, char **av)
{
	t_philo		philo;

	if (!av)
		return (-printf("%s\n", ERR_PARSING_ERROR));
	philo.args.philo_nb = (t_uint)ft_atoi(av[1]);
	philo.args.tt_die = (t_uint)ft_atoi(av[2]);
	philo.args.tt_eat = (t_uint)ft_atoi(av[3]);
	philo.args.tt_sleep = (t_uint)ft_atoi(av[4]);
	if (ac == 6)
		philo.args.meal_nb = ft_atoi(av[5]);
	else
		philo.args.meal_nb = -1;
	if (parse_error(&philo) < 0 || init_philo_data(&philo) < 0)
		return (-1);
	return (1);
}
