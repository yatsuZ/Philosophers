/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:51:49 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 20:43:24 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	ft_eat(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	if (!is_finish(d, m, philo))
		return (1);
	ft_message(get_time_pass(d->t_start, &(d->err)), philo, "is eating", m);
	pthread_mutex_lock(m.eat);
	philo->nbr_eat++;
	philo->t_last_eat = get_time_pass(d->t_start, &(d->err));
	pthread_mutex_unlock(m.eat);
	ft_sleep(d, m, p.t_eat);
	return (0);
}
