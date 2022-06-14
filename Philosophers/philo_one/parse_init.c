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
	t_mutex		*spoons;
	int			i;

	spoons = malloc(sizeof(pthread_mutex_t) * philo.args.philo_nb);
	if (!spoons)
		return (-printf("%s\n", ERR_MALLOC));
	all = (t_philo *)malloc(sizeof(t_philo) * philo.args.philo_nb);
	if (!(all))
		return (-printf("%s\n", ERR_MALLOC));
	i = -1;
	while (++i < (int)philo.args.philo_nb)
	{
		all[i] = philo;
		pthread_mutex_init(&spoons[i], NULL);
		pthread_mutex_init(&philo.eating[i], NULL);
		all[i].nb = (t_uint)i + 1;
		all[i].spoon_left = &spoons[i];
		if (i == (int)philo.args.philo_nb - 1)
			all[i].spoon_right = &spoons[0];
		else
			all[i].spoon_right = &spoons[i + 1];
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
	t_mutex		output;
	int			dead_bool;
	int			philo_full_nb;
	int			fire;

	philo->eating = malloc(sizeof(pthread_mutex_t) * philo->args.philo_nb);
	if (!(philo->eating))
		return (-printf("%s\n", ERR_MALLOC));
	philo_full_nb = 0;
	dead_bool = -1;
	fire = -1;
	philo->meals = philo->args.meal_nb;
	philo->start_time = get_time();
	philo->last_meal = get_time_from_start(philo);
	philo->full = &philo_full_nb;
	philo->print = &output;
	philo->dead = &dead_bool;
	philo->feu = &fire;
	pthread_mutex_init(philo->print, NULL);
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
