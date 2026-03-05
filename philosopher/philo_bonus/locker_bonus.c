/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:10:54 by mmusquer          #+#    #+#             */
/*   Updated: 2026/02/27 12:29:16 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

long	check_last_bite(t_philo *philo)
{
	long	tmp;

	sem_wait(philo->data->bite);
	tmp = get_time() - philo->last_bite;
	sem_post(philo->data->bite);
	return (tmp);
}

int	lock_nb_bite_need(t_philo *philo)
{
	int	tmp;

	sem_wait(philo->data->bite);
	tmp = philo->data->nb_bite_need;
	sem_post(philo->data->bite);
	return (tmp);
}

int	lock_nb_bite(t_philo *philo)
{
	int	tmp;

	sem_wait(philo->data->bite);
	tmp = philo->nb_bite;
	sem_post(philo->data->bite);
	return (tmp);
}

int	is_dead(t_philo *philo)
{
	int	tmp;

	sem_wait(philo->data->death);
	tmp = philo->he_dead;
	sem_post(philo->data->death);
	return (tmp);
}
