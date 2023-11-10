/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:23:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 18:47:41 by yatsu            ###   ########.fr       */
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


void	*thread_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!is_finish(philo))// c'est fini si quelqun est mort ou si tout le mondde a mange x fois.
	{
		usleep(100);
		// ft_take_fork(philo);
		// ft_eat(philo);
		// ft_sleep(philo);
		// ft_think(philo);
	}
	return (NULL);
}

// 1. Faire que data est un tableau de mutex de fourchette init free etc
// 2. Quand le thread commence faire que tout le monde doit prend une fouchette et verifier qu