/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:03:41 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/02 03:37:52 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	is_dead(t_data *d, t_parametre p, t_all_mutex m)
{
	int		i;
	t_philo	*philo;
	long	duration;

	i = 0;
	while (d->all_philo[i])
	{
		philo = d->all_philo[i++];
		duration = get_time_pass(d->t_start, &(d->err));
		if (d->err)
			return (1);
		pthread_mutex_lock(m.eat);
		if (duration - philo->t_last_eat >= p.t_die)
		{
			pthread_mutex_unlock(m.eat);
			duration = get_time_pass(d->t_start, &(d->err));
			ft_message(duration, philo->id, "died", m);
			pthread_mutex_lock(m.check);
			d->evryone_is_alive = FALSE;
			pthread_mutex_unlock(m.check);
			return (1);
		}
		pthread_mutex_unlock(m.eat);
	}
	return (0);
}

void	cheack_all_thread(t_data *d, t_parametre p, t_all_mutex m)
{
	int	vrai;

	vrai = TRUE;
	while (vrai)
	{
		if (is_dead(d, p, m))
			vrai = FALSE ;
		pthread_mutex_lock(m.eat);
		if (p.n_eat != -1 && vrai)
		{
			if (!d->philo_eat)
			{
				d->evryone_is_alive = 1;
				vrai = FALSE ;
			}
		}
		pthread_mutex_unlock(m.eat);
		if (d->err)
			vrai = FALSE ;
	}
}

void	thread_start(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->param.n_philo)
	{
		if (pthread_create(&(d->threads[i]), NULL, routine, d->all_philo[i]))
			d->err = 7;
	}
	cheack_all_thread(d, d->param, d->mutexs);
	i = -1;
	while (++i < d->param.n_philo)
	{
		if (pthread_join(d->threads[i], NULL) != 0)
			d->err = 8;
	}
}
