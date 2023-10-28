/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:24:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 22:03:22 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

// void	*thread_philo(void *arg)
// {
// 	t_philo	*philo;
// 	philo = (t_philo *)arg;
// 	t_data	*data = philo->data;
// 	// char	res;
// 	// philo->data->nbr_thread_actif++;
// 	// while (philo->data->nbr_thread_actif != philo->data->n_philo)
// 	// 	sleep(1);
// 	pthread_mutex_lock(data->use_printf);
// 	printf("first");
// 	pthread_mutex_unlock(data->use_printf);
// 	// printf("\n%d\tBonjour je suis %s\n", philo->id, philo->nom);
// 	return (NULL);
// }

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
