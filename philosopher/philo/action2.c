/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:18:12 by mmusquer          #+#    #+#             */
/*   Updated: 2026/03/02 16:19:24 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	think(t_philo *philo)
{
	int	time_to_think;

	if (is_dead(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (is_dead(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return ;
	}
	printf("\033[35;01m%ld ms Philosopher %d is thinking\033[00m\n", (get_time()
			- philo->data->starting_time), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	if (philo->data->nb_philo % 2 == 0)
		time_to_think = philo->data->time_to_eat - philo->data->time_to_sleep;
	else
		time_to_think = (philo->data->time_to_eat * 2)
			- philo->data->time_to_sleep;
	if (time_to_think > 0)
		ft_usleep(time_to_think);
}
