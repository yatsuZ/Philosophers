/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:32:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 15:10:18 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

/*
	@brief Recupere le temp ecoullé entre start et maintenant
	en milliseconde.
	A note que 1s = 1 000 milliseconde.
*/
long	get_time_pass(struct timeval start, int *error)
{
	struct timeval	now;
	long			pass;

	if (*error)
		return (0);
	if (gettimeofday(&(now), NULL) == -1)
		return (*error = 3, 0);
	pass = now.tv_sec * 1000 + now.tv_usec / 1000;
	pass = pass - (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (pass);
}

long	ft_sleep(t_data *data, long t_sleep, long check_point)
{
	long	pass_s_fix;
	long	duration;
	long	last_dif;

	pass_s_fix = get_time_pass(data->t_start, &(data->err));
	duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
	if (data->err)
		return (0);
	last_dif = duration;
	while (t_sleep > duration)
	{
		if (duration - last_dif > check_point)
		{
			printf("%ld\tseconde\n", duration / 1000);
			// divise par 1000 pour avoir des seconde
			last_dif = duration;
		}
		// usleep(50); Inutile pour linstant
		duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
		if (data->err)
			return (0);
	}
	return (duration);
}
