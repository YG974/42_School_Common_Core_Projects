/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:44:39 by ygeslin           #+#    #+#             */
/*   Updated: 2021/05/12 16:59:46 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <time.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

/*
** ERRORS
*/

# define ERR_MISSING_ARGS "ERROR : missing argument(s)"
# define ERR_TO_MANY_ARGS "ERROR : too many arguments"
# define ERR_PARSING_ERROR "ERROR : parsing error"
# define ERR_PHILO "ERROR : philosophers nb should be between 1 and 200"
# define ERR_TIME_TO "ERROR : time to eat/sleep/die should be greater than 60"
# define ERR_MALLOC "ERROR : malloc failure"
# define ERR_GET_TIME "ERROR : fail to load time of day"

/*
** EVENTS
*/

# define EAT "is eating"
# define SLEEP "is sleeping"
# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define DIED "died"

int							g_print_dead;
typedef unsigned int		t_uint;
typedef pthread_mutex_t		t_mutex;

typedef struct s_arguments
{
	t_uint				tt_die;
	t_uint				tt_eat;
	t_uint				tt_sleep;
	t_uint				philo_nb;
	int					meal_nb;
}						t_arguments;

typedef struct s_philo
{
	pthread_t			thread_nb;
	pthread_t			monitor_nb;
	t_mutex				*eating;
	t_mutex				*spoon_left;
	t_mutex				*spoon_right;
	t_mutex				*print;
	int					*dead;
	int					*full;
	int					*feu;
	t_arguments			args;
	int					meals;
	t_uint				nb;
	t_uint				last_meal;
	t_uint				start_time;
	t_uint				curr_time;
}						t_philo;

/*
** utils.c
*/

int						ft_tnrvfrr(const char *str);
int						ft_atoi(const char *str);
t_uint					get_time(void);
t_uint					get_time_from_start(t_philo *philo);
void					wait_for_it(t_philo *philo, t_uint waiting_time);

/*
** parse_init.c
*/

void					init_threads_philo(t_philo *th);
int						init_philo(t_philo philo);
int						parse_error(t_philo *philo);
int						init_philo_data(t_philo *philo);
int						parse_input(int ac, char **av);

/*
** events.c
*/

void					print(t_philo *philo, char *event, int nb);
void					philo_think(t_philo *philo);
void					philo_sleep(t_philo *philo);
void					philo_eat(t_philo *philo);
void					join_threads(t_philo *th);

/*
** main.c
*/

void					*routine_monitor(void *philo_ptr);
void					*routine_philo(void *philo_ptr);
int						destroy_all(t_philo *th);
void					philo_master_monitor_main(t_philo *philo);
void					*philo_master_monitor(void *philo_ptr);
int						main(int ac, char **av);
#endif
