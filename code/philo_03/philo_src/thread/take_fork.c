/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:28:37 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 23:14:41 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	give_first_fork(t_philo *philo, t_parametre p, t_all_mutex m)
{
	int	index_fork;

	if (philo->id % 2 == 0)
		index_fork = philo->id;
	else
		index_fork = philo->id + 1;
	if (index_fork == p.n_philo)
		index_fork = 0;
	pthread_mutex_unlock(m.all_fork[index_fork]);
}

void	give_fork(t_philo *philo, t_parametre p, t_all_mutex m)
{
	// int	index_fork;

	if (p.n_philo > 1)
	{
		pthread_mutex_unlock(m.all_fork[philo->first_fork]);
		pthread_mutex_unlock(m.all_fork[philo->second_fork]);

		// if (philo->id % 2 == 0)
		// 	index_fork = philo->id + 1;
		// else
		// 	index_fork = philo->id;
		// if (index_fork == p.n_philo)
		// 	index_fork = 0;
		// pthread_mutex_unlock(m.all_fork[index_fork]);
		// give_first_fork(philo, p, m);
	}
	else
		pthread_mutex_unlock(m.all_fork[0]);
	// ft_message(get_time_pass(philo->data->t_start, &(philo->data->err)), philo, "GIVE FORK", m);
}

int	ft_take_fork(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	if (!is_finish(d, m, philo))
		return (1);
	ft_message(get_time_pass(d->t_start, &(d->err)), philo, "has taken a fork 1 (faudra retirer le 1 et 2)", m);
	pthread_mutex_unlock(m.all_fork[philo->first_fork]);
	if (p.n_philo != 1)
	{
		pthread_mutex_unlock(m.all_fork[philo->second_fork]);
		ft_message(get_time_pass(d->t_start, &(d->err)), philo, "has taken a fork 2", m);
	}
	else
		ft_sleep(d, m, p.t_die);
	return (0);
}
