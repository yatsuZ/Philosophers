/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:23:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 16:35:52 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

// Return 1 si il y a y a 1 philosophe mort OU si
// ce philosophe à mange x_nombre de fois OU si y a une erreur.
int	is_finish(t_philo *philo)
{
	t_data	*data;
	int		res;

	res = 0;
	data = philo->data;
	pthread_mutex_lock(data->write_data);
	if (data->evryone_is_alive == FALSE)
		res = 1;
	else if (data->n_eat == 0)
		res = 1;
	else if (data->err)
		res = 1;
	return (pthread_mutex_unlock(data->write_data), res);
}

void	is_dead(t_philo *philo, long duration)
{
	t_data	*d;

	d = philo->data;
	if (duration >= d->t_die)
	{
		pthread_mutex_lock(d->write_data);
		d->evryone_is_alive = FALSE;
		pthread_mutex_unlock(d->write_data);
		ft_message(get_time_pass(philo->data->t_start, &(philo->data->err)), philo->id, "died", philo->data);
	}
}

void	*thread_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!is_finish(philo))// c'est fini si quelqun est mort ou si tout le mondde a mange x fois.
	{
		is_dead(philo, get_time_pass(philo->data->t_start, &(philo->data->err)));
		// ft_take_fork(philo);
		// ft_eat(philo);
		// ft_sleep(philo);
		// ft_think(philo);
	}
	return (NULL);
}
