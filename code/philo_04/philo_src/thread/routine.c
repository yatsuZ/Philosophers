/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:03:44 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 18:16:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	is_finish(t_data *d, t_all_mutex m)
{
	pthread_mutex_lock(m.check);
	if (d->err == 0 && d->evryone_is_alive)
		return (pthread_mutex_unlock(m.check), 1);
	d->evryone_is_alive = FALSE;
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
		if (philo_think(philo, d, m))
			return (NULL);
	}
	return (NULL);
}
