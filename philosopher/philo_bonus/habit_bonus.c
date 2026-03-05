/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habit_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:20:57 by mmusquer          #+#    #+#             */
/*   Updated: 2026/03/03 11:42:30 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

static void	fork_to_bite(t_philo *philo)
{
	take_fork(philo);
	take_fork(philo);
	take_bite(philo);
	put_down_fork(philo);
}

static void	check_delay_time(t_philo *philo)
{
	if (philo->data->nb_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(philo->data->time_to_eat);
	}
	else
	{
		if (philo->id % 3 == 2)
			ft_usleep(philo->data->time_to_eat);
		else if (philo->id % 3 == 0)
			ft_usleep(philo->data->time_to_eat * 2);
	}
}

void	*grim_reaper(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (lock_nb_bite(philo) == lock_nb_bite_need(philo))
			break ;
		if (check_last_bite(philo) > philo->data->time_to_die)
		{
			sem_wait(philo->data->print);
			printf("\033[31;01m%ld ms Philosopher %d is dead\033[00m\n",
				(get_time() - philo->data->starting_time), philo->id);
			sem_close(philo->data->bite);
			sem_close(philo->data->death);
			sem_close(philo->data->fork);
			sem_close(philo->data->print);
			sem_close(philo->data->sit);
			free(philo->data->philos);
			exit(1);
		}
		ft_usleep(2);
	}
	return (NULL);
}

void	habit(t_philo *philo)
{
	pthread_create(&philo->thread, NULL, grim_reaper, philo);
	pthread_detach(philo->thread);
	check_delay_time(philo);
	while (1)
	{
		sem_wait(philo->data->sit);
		fork_to_bite(philo);
		sem_post(philo->data->sit);
		sem_wait(philo->data->bite);
		philo->nb_bite++;
		sem_post(philo->data->bite);
		if (lock_nb_bite(philo) == lock_nb_bite_need(philo))
		{
			end_fork(philo);
			exit(0);
		}
		sleeping(philo);
		think(philo);
	}
}
