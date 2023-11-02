/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:51:49 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/02 03:38:46 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	ft_eat(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "is eating", m);
	philo->nbr_eat++;
	pthread_mutex_lock(m.eat);
	if (p.n_eat != -1)
	{
		if (philo->nbr_eat == p.n_eat)
			d->philo_eat--;
	}
	philo->t_last_eat = get_time_pass(d->t_start, &(d->err));
	pthread_mutex_unlock(m.eat);
	ft_sleep(d, m, p.t_eat);
	give_fork(philo, p, m);
}
