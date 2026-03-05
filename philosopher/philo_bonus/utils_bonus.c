/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:45:06 by mmusquer          #+#    #+#             */
/*   Updated: 2026/03/02 13:09:35 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	error_end(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	destroy_semaphore(t_data *data)
{
	sem_post(data->print);
	sem_close(data->fork);
	sem_unlink("/fork");
	sem_close(data->print);
	sem_unlink("/print");
	sem_close(data->sit);
	sem_unlink("/sit");
	sem_close(data->bite);
	sem_unlink("/bite");
	sem_close(data->death);
	sem_unlink("/death");
}

void	end_fork(t_philo *philo)
{
	sem_close(philo->data->bite);
	sem_close(philo->data->death);
	sem_close(philo->data->fork);
	sem_close(philo->data->print);
	sem_close(philo->data->sit);
	free(philo->data->philos);
}
