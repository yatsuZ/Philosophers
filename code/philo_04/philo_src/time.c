/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:21 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 15:49:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

long	get_time_pass(struct timeval start, int *error)
{
	struct timeval	now;
	long			pass;

	if (gettimeofday(&(now), NULL) == -1)
		return (*error = 5, 0);
	pass = now.tv_sec * 1000 + now.tv_usec / 1000;
	pass = pass - (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (pass);
}

long	ft_sleep(t_data *data, t_all_mutex mutexs, int t_sleep)
{
	long	pass_s_fix;
	long	duration;

	if (!data || data->err)
		return (-1);
	pass_s_fix = get_time_pass(data->t_start, &(data->err));
	duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
	while ((long)t_sleep > duration)
	{
		pthread_mutex_lock(mutexs.check);
		if (data->evryone_is_alive == FALSE)
			return (pthread_mutex_unlock(mutexs.check), 0);
		pthread_mutex_unlock(mutexs.check);
		duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
		if (data->err)
			return (0);
	}
	return (duration);
}
