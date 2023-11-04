/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:03:41 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 16:36:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	la_morgue(t_philo *philo, t_parametre p, t_all_mutex m, long duration)
{
	t_data	*d;

	d = philo->data;
	pthread_mutex_lock(m.eat);
	if (p.n_eat != -1 && p.n_eat <= philo->nbr_eat)
		return (pthread_mutex_unlock(m.eat), 0);
	if (duration - philo->t_last_eat >= (long)p.t_die)
	{
		pthread_mutex_unlock(m.eat);
		pthread_mutex_lock(m.check);
		d->evryone_is_alive = FALSE;
		pthread_mutex_lock(m.use_printf);
		d->one_dead = TRUE;
		printf("%ld %d \tdied\n", duration, philo->id);
		pthread_mutex_unlock(m.use_printf);
		return (pthread_mutex_unlock(m.check), 1);
	}
	return (pthread_mutex_unlock(m.eat), 0);
}

int	evryone_eat(t_data *d, t_parametre p, t_all_mutex m)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (d->all_philo[i])
	{
		philo = d->all_philo[i++];
		pthread_mutex_lock(m.eat);
		if (p.n_eat == -1 || p.n_eat > philo->nbr_eat)
			return (pthread_mutex_unlock(m.eat), 0);
		pthread_mutex_unlock(m.eat);
	}
	pthread_mutex_lock(m.check);
	d->evryone_is_alive = FALSE;
	pthread_mutex_unlock(m.check);
	return (1);
}

void	cheack_all_thread(t_data *d, t_parametre p, t_all_mutex m)
{
	int		vrai;
	int		i;
	t_philo	*philo;
	long	duration;

	vrai = TRUE;
	while (vrai)
	{
		i = 0;
		while (vrai && d->all_philo[i])
		{
			philo = d->all_philo[i++];
			duration = get_time_pass(d->t_start, &(d->err));
			if (d->err)
				vrai = FALSE;
			if (la_morgue(philo, p, m, duration))
				vrai = FALSE;
		}
		if (evryone_eat(d, p, m))
			vrai = FALSE ;
		pthread_mutex_lock(m.check);
		if (d->err)
			vrai = FALSE ;
		pthread_mutex_unlock(m.check);
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
