/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:23:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 23:35:02 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

// Return 1 si il y a y a 1 philosophe mort OU si
// ce philosophe à mange x_nombre de fois OU si y a une erreur.
int	is_finish(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(data->check);
	if (data->finish)
		return (pthread_mutex_unlock(data->check), 1);
	pthread_mutex_unlock(data->check);
	if (data->err)
		return (1);
	return (0);
}

void	ft_take_fork(t_philo *philo)
{
	t_data	*d;
	int		index_fork;

	d = philo->data;
	if (philo->id % 2 == 0)
		index_fork = philo->id;
	else
		index_fork = philo->id + 1;
	if (index_fork == philo->data->n_philo)
		index_fork = 0;
	pthread_mutex_lock(d->all_fork[index_fork]);
	ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "has taken a fork 1", d);
	if (d->n_philo != 1)
	{
		if (philo->id % 2 == 0)
			index_fork = philo->id + 1;
		else
			index_fork = philo->id;
		if (index_fork == philo->data->n_philo)
			index_fork = 0;
		pthread_mutex_lock(d->all_fork[index_fork]);
		ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "has taken a fork 2", d);
	}
	else
		ft_sleep(d, d->t_die);
}

void	ft_eat(t_philo *philo, t_data *d)
{
	ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "is eating", d);
	philo->nbr_eat++;
	pthread_mutex_lock(d->eat);
	if (philo->nbr_eat == d->n_eat)
		d->evryone_eat++;
	pthread_mutex_unlock(d->eat);
	philo->t_last_eat = get_time_pass(d->t_start, &(d->err));
	ft_sleep(d, d->t_eat);
	pthread_mutex_unlock(d->all_fork[philo->id]);
	if (d->n_philo != 1 && d->n_philo - 1 != philo->id)
		pthread_mutex_unlock(d->all_fork[philo->id + 1]);
	else if (d->n_philo - 1 == philo->id)
		pthread_mutex_unlock(d->all_fork[0]);
}

void	*thread_philo(void *arg)
{
	t_philo	*philo;
	t_data	*d;

	philo = (t_philo *)arg;
	d = philo->data;
	while (!is_finish(philo))// c'est fini si quelqun est mort ou si tout le mondde a mange x fois.
	{
		ft_take_fork(philo);
		if (!is_finish(philo))
		{
			ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "FINI", d);
			pthread_mutex_unlock(d->all_fork[philo->id]);
			if (d->n_philo != 1 && d->n_philo - 1 != philo->id)
				pthread_mutex_unlock(d->all_fork[philo->id + 1]);
			else if (d->n_philo != 1 &&d->n_philo - 1 == philo->id)
				pthread_mutex_unlock(d->all_fork[0]);
			return (NULL);
		}
		ft_eat(philo, d);
		// ft_sleep(philo);
		// ft_think(philo);
	}
	return (NULL);
}

// 1. Faire que data est un tableau de mutex de fourchette init free etc
// 2. Quand le thread commence faire que tout le monde doit prend une fouchette et verifier qu

Refaire en utilisant des atribut plus coherent et de meillieur structure 
faire dans mon main principal un bon checker