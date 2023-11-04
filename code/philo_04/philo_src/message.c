/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:43:04 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 16:51:24 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

void	ft_message(t_data *d, t_philo *philo, char *message, t_all_mutex mutexs)
{
	long	time;
	int		err;

	if (!philo)
		return ;
	err = 0;
	time = get_time_pass(d->t_start, &err);
	pthread_mutex_lock(mutexs.check);
	if (!d->err && err)
		d->err = err;
	else if (d->evryone_is_alive == TRUE && !d->err)
	{
		pthread_mutex_unlock(mutexs.check);
		pthread_mutex_lock(mutexs.use_printf);
		if (d->one_dead == FALSE)
			printf("%ld %d \t%s\t\t%d %d\n", time, philo->id, message, philo->first_fork, philo->second_fork);
		pthread_mutex_unlock(mutexs.use_printf);
		return ;
	}
	pthread_mutex_unlock(mutexs.check);
}
