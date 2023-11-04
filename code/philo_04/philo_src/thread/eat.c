/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:51:49 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 16:53:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	ft_eat(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	if (!is_finish(d, m))
		return (1);
	ft_message(d, philo, "is eating", m);
	pthread_mutex_lock(m.eat);
	philo->nbr_eat++;
	philo->t_last_eat = get_time_pass(d->t_start, &(d->err));
	pthread_mutex_unlock(m.eat);
	ft_sleep(d, m, p.t_eat);
	pthread_mutex_unlock(m.all_fork[philo->first_fork]);
	pthread_mutex_unlock(m.all_fork[philo->second_fork]);
	return (0);
}
