/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:45:21 by mmusquer          #+#    #+#             */
/*   Updated: 2026/03/02 16:43:43 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct z_philo
{
	int				id;
	long			last_bite;
	int				nb_bite;

	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_bite_need;
	long			starting_time;
	int				he_dead;

	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	bite_mutex;

	t_philo			*philos;
}					t_data;

/*TIME*/

long				get_time(void);
void				ft_usleep(long duration);

/*PARSING*/

void				parsing(int ac, char **av, t_data *data);
int					atoi_safe(const char *str, int *error);

/*INIT*/

void				init_mutex(t_data *data);
void				init_philo(t_data *data);

/*HABIT*/

void				*habit(void *args);
void				think(t_philo *philo);
int					take_left_fork(t_philo *philo);
int					take_right_fork(t_philo *philo);
void				take_bite(t_philo *philo);
void				sleeping(t_philo *philo);
void				put_down_fork(t_philo *philo);

/*MONITORING*/

void				eye_of_sauron(t_data *data);

/*LOCKER*/

long				check_last_bite(t_data *data, int j);
int					is_dead(t_philo *philo);
int					lock_nb_bite_need(t_philo *philo);
int					lock_nb_bite(t_philo *philo);

/*UTILS*/

void				error_end(char *msg);
int					ft_strlen(char *str);
void				destroy_mutex(t_data *data);

#endif