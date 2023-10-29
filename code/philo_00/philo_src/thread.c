/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:23:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 23:32:06 by yatsu            ###   ########.fr       */
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
	printf("first my id = %d\n", philo->id);
	pthread_mutex_unlock(data->use_printf);
	return (NULL);
}
