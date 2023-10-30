/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:23:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/30 01:03:16 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

void	*thread_philo(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(data->use_printf);
	data->nbr_thread_actif++;
	if (data->n_eat > 0)
		data->n_eat--;
	if (data->evryone_is_alive)
		printf("first my id = %d\n", philo->id);
	else
		printf("second my id = %d\n", philo->id);
	data->evryone_is_alive = FALSE;
	pthread_mutex_unlock(data->use_printf);
	return (NULL);
}
