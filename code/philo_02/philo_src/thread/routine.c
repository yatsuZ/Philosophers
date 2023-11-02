/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:03:44 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/02 03:35:55 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	is_finish(t_data *d, t_all_mutex m)
{
	pthread_mutex_lock(m.check);
	if (d->err || d->evryone_is_alive)
		return (pthread_mutex_unlock(m.check), 1);
	pthread_mutex_unlock(m.check);
	return (0);
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
		if (!is_finish(d, m))
			return (NULL);
		ft_take_fork(philo, d, p, m);
		if (!is_finish(d, m))
			return (give_fork(philo, p, m), NULL);
		ft_eat(philo, d, p, m);
		// ft_sleep(philo);
		// ft_think(philo);
		// ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "1 tour", m);
	}
	return (NULL);
}
