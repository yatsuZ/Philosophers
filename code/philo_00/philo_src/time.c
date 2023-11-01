/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:03:21 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 15:56:29 by yatsu            ###   ########.fr       */
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

// usleep(50); Inutile pour linstant

/// @brief FT_SLEEP = attend t_sleep en milliseconde si la durée dattente est plus grande que celle de la mort alors 
/// @param data 
/// @param t_sleep 
/// @param check_point 
/// @return 
long	ft_sleep(t_data *data, t_philo *philo, long t_sleep, long check_point)
{
	long	pass_s_fix;
	long	duration;
	long	last_dif;
	(void)	philo;

	pass_s_fix = get_time_pass(data->t_start, &(data->err));
	duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
	if (data->err)
		return (-1);
	last_dif = duration;
	while (t_sleep > duration)
	{
		if (duration - last_dif > check_point)
		{
			printf("%ld\tseconde\n", duration / 1000);
			last_dif = duration;
		}
		duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
		if (data->err)
			return (0);
	}
	return (duration);
}