/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:28:37 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/02 03:15:31 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	give_fork(t_philo *philo, t_parametre p, t_all_mutex m)
{
	pthread_mutex_unlock(m.all_fork[philo->id]);
	if (p.n_philo > 1 && philo->id + 1 == p.n_philo)
		pthread_mutex_unlock(m.all_fork[0]);
	else if (p.n_philo > 1)
		pthread_mutex_unlock(m.all_fork[philo->id + 1]);
	ft_message(get_time_pass(philo->data->t_start, &(philo->data->err)), philo->id, "GIVE FORK", m);
}

void	get_second_fork(t_philo *philo, t_parametre p, t_all_mutex m)
{
	int	index_fork;

	if (philo->id % 2 == 0)
		index_fork = philo->id + 1;
	else
		index_fork = philo->id;
	if (index_fork == p.n_philo)
		index_fork = 0;
	pthread_mutex_lock(m.all_fork[index_fork]);
}

void	get_first_fork(t_philo *philo, t_parametre p, t_all_mutex m)
{
	int	index_fork;

	if (philo->id % 2 == 0)
		index_fork = philo->id;
	else
		index_fork = philo->id + 1;
	if (index_fork == p.n_philo)
		index_fork = 0;
	pthread_mutex_lock(m.all_fork[index_fork]);
}

void	ft_take_fork(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	get_first_fork(philo, p, m);
	ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "has taken a fork 1", m);
	if (p.n_philo != 1)
	{
		get_second_fork(philo, p, m);
		ft_message(get_time_pass(d->t_start, &(d->err)), philo->id, "has taken a fork 2", m);
	}
	else
		ft_sleep(d, m, p.t_die);
}
