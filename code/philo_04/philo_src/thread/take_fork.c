/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:28:37 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 20:37:12 by yzaoui           ###   ########.fr       */
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
	if (p.n_philo > 1)
	{
		pthread_mutex_unlock(m.all_fork[philo->second_fork]);
		pthread_mutex_unlock(m.all_fork[philo->first_fork]);
	}
	else
		pthread_mutex_unlock(m.all_fork[0]);
}

int	ft_take_fork(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	if (!is_finish(d, m))
		return (1);
	ft_message(d, philo, "has taken a fork", m);
	pthread_mutex_lock(m.all_fork[philo->first_fork]);
	if (p.n_philo != 1)
	{
		pthread_mutex_lock(m.all_fork[philo->second_fork]);
		ft_message(d, philo, "has taken a fork", m);
	}
	else
		ft_sleep(d, m, p.t_die);
	return (0);
}
