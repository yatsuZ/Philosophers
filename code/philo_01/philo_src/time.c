/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:21 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 20:16:53 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

/*
	@brief Recupere le temp ecoullé entre start et maintenant
	en milliseconde.
	A note que 1s = 1 000 milliseconde.
*/
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


/// @brief FT_SLEEP = attend t_sleep en milliseconde si la durée dattente est plus grande que celle de la mort alors 
/// @param data 
/// @param t_sleep 
/// @param check_point 
/// @return 
long	ft_sleep(t_data *data, int t_sleep)
{
	long	pass_s_fix;
	long	duration;

	pass_s_fix = get_time_pass(data->t_start, &(data->err));
	duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
	if (data->err)
		return (-1);
	while ((long)t_sleep > duration)
	{
		pthread_mutex_lock(data->check);
		if (data->evryone_is_alive == FALSE)
			return (pthread_mutex_unlock(data->check), 0);
		pthread_mutex_unlock(data->check);
		duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
		if (data->err)
			return (0);
		usleep(50);
	}
	return (duration);
}
