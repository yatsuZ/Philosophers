/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:03:44 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 20:31:14 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	is_finish(t_data *d, t_all_mutex m, t_philo *philo)
{
	pthread_mutex_lock(m.check);
	pthread_mutex_lock(m.eat);
	if (d->param.n_eat >= 0 && philo->nbr_eat >= d->param.n_eat)
		return (pthread_mutex_unlock(m.eat), pthread_mutex_unlock(m.check), 0);
	pthread_mutex_unlock(m.eat);
	if (d->err || d->evryone_is_alive)
		return (pthread_mutex_unlock(m.check), 1);
	return (pthread_mutex_unlock(m.check), 0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_data		*d;
	t_all_mutex	m;
	t_parametre	p;

	philo = (t_philo *)arg;
	d = philo->data;
	m = d->mutexs;
	p = d->param;
	while (1)
	{
		if (ft_take_fork(philo, d, p, m))
			return (NULL);
		if (ft_eat(philo, d, p, m))
			return (NULL);
		if (philo_sleep(philo, d, p, m))
			return (NULL);
		if (philo_think(philo, d, p, m))
			return (NULL);
	}
	return (NULL);
}
