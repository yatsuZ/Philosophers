/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:43:04 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 20:44:05 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

void	ft_message(long time, t_philo *philo, char *message, t_all_mutex mutexs)
{
	int		id;

	id = philo->id;
	pthread_mutex_lock(mutexs.use_printf);
	printf("%ld\t\t%d\t%s\n", time, id, message);
	pthread_mutex_unlock(mutexs.use_printf);
}


// void	ft_message(long time, t_philo *philo, char *message, t_all_mutex mutexs)
// {
// 	int		id;
// 	t_data	*d;

// 	if (!philo)
// 		return ;
// 	id = philo->id;
// 	d = philo->data;
// 	pthread_mutex_lock(mutexs.check);
// 	if (d->evryone_is_alive == TRUE)
// 	{
// 		pthread_mutex_unlock(mutexs.check);
// 		pthread_mutex_lock(mutexs.use_printf);
// 		if (d->time_of_death == -1)
// 			printf("%ld %d \t%s\n", time, id, message);
// 		pthread_mutex_unlock(mutexs.use_printf);
// 		return ;
// 	}
// 	pthread_mutex_unlock(mutexs.check);
// }