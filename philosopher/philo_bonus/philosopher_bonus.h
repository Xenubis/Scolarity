/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:45:21 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/27 12:29:40 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_BONUS_H
# define PHILOSOPHER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define ROUGE

typedef struct z_philo
{
	int				id;
	long			last_bite;
	int				nb_bite;
	int				he_dead;

	pthread_t		thread;
	pid_t			pid;

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
	int				nb_finish_pid;

	sem_t			*fork;
	sem_t			*sit;
	sem_t			*print;
	sem_t			*bite;
	sem_t			*death;

	t_philo			*philos;
}					t_data;

/*TIME*/

long				get_time(void);
void				ft_usleep(long duration);

/*PARSING*/

void				parsing(int ac, char **av, t_data *data);
int					atoi_safe(const char *str, int *error);

/*INIT*/

void				init_semaphore(t_data *data);
void				init_philo(t_data *data);

/*HABIT*/

void				habit(t_philo *philo);
void				take_fork(t_philo *philo);
void				think(t_philo *philo);
void				take_bite(t_philo *philo);
void				sleeping(t_philo *philo);
void				put_down_fork(t_philo *philo);

/*MONITORING*/

void				*grim_reaper(void *args);

/*UTILS*/

void				error_end(char *msg);
int					ft_strlen(char *str);
void				destroy_semaphore(t_data *data);
void				end_fork(t_philo *philo);

/*LOCKER*/

long				check_last_bite(t_philo *philo);
int					lock_nb_bite_need(t_philo *philo);
int					lock_nb_bite(t_philo *philo);
int					is_dead(t_philo *philo);

#endif