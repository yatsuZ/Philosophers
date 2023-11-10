/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_and_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:11:43 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/10 12:41:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	give_fork(t_philo *philo, t_data *data)
{
	if (data->param.n_philo > 1)
	{
		pthread_mutex_unlock(data->mutexs.all_fork[philo->second_fork]);
		pthread_mutex_unlock(data->mutexs.all_fork[philo->first_fork]);
	}
	else
		pthread_mutex_unlock(data->mutexs.all_fork[0]);
}

int	ft_take_fork(t_philo *philo, t_data *data)
{
	if (!is_finish(data))
		return (1);
	ft_message(philo, "has taken a fork", data->mutexs);
	pthread_mutex_lock(data->mutexs.all_fork[philo->first_fork]);
	if (data->param.n_philo != 1)
	{
		pthread_mutex_lock(data->mutexs.all_fork[philo->second_fork]);
		ft_message(philo, "has taken a fork", data->mutexs);
	}
	else
		ft_sleep(data->param.t_die);
	return (0);
}

int	is_finish(t_data *data)
{
	pthread_mutex_lock(data->mutexs.check);
	if (data->evryone_is_alive)
		return (pthread_mutex_unlock(data->mutexs.check), 1);
	data->evryone_is_alive = FALSE;
	return (pthread_mutex_unlock(data->mutexs.check), 0);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		ft_sleep(philo->data->param.t_eat / 4);
	while (1)
	{
		if (ft_take_fork(philo, philo->data))
			return (NULL);
		if (ft_eat(philo, philo->data))
			return (NULL);
		if (philo_sleep(philo, philo->data))
			return (NULL);
		if (philo_think(philo, philo->data))
			return (NULL);
	}
	return (NULL);
}
