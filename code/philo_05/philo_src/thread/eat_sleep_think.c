/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:09:48 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/05 00:35:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	ft_eat(t_philo *philo, t_data *data)
{
	if (!is_finish(data))
		return (give_fork(philo, data), 1);
	ft_message(philo, "is eating", data->mutexs);
	pthread_mutex_lock(data->mutexs.eat);
	philo->nbr_eat++;
	philo->t_last_eat = get_time_pass(data->t_start);
	pthread_mutex_unlock(data->mutexs.eat);
	ft_sleep(data->param.t_eat);
	give_fork(philo, data);
	return (0);
}

int	philo_sleep(t_philo *philo, t_data *data)
{
	ft_message(philo, "is sleeping", data->mutexs);
	ft_sleep(data->param.t_sleep);
	return (0);
}

int	philo_think(t_philo *philo, t_data *data)
{
	ft_message(philo, "is thinking", data->mutexs);
	if (data->param.n_philo % 2 == 1)
		ft_sleep(data->param.t_eat / 2);
	return (0);
}
