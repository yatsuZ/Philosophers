/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:12:32 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/04 23:55:52 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

static int	someone_died(t_philo *philo, t_data *data, long duration)
{
	pthread_mutex_lock(data->mutexs.eat);
	if (data->param.n_eat != -1 && data->param.n_eat <= philo->nbr_eat)
		return (pthread_mutex_unlock(data->mutexs.eat), 0);
	if (duration - philo->t_last_eat >= (long)data->param.t_die)
	{
		pthread_mutex_unlock(data->mutexs.eat);
		pthread_mutex_lock(data->mutexs.check);
		data->evryone_is_alive = FALSE;
		pthread_mutex_lock(data->mutexs.use_printf);
		data->one_dead = TRUE;
		printf("%ld %d died\n", duration, philo->id + 1);
		pthread_mutex_unlock(data->mutexs.use_printf);
		pthread_mutex_unlock(data->mutexs.check);
		return (1);
	}
	pthread_mutex_unlock(data->mutexs.eat);
	return (0);
}

static int	evryone_to_eat(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (data->all_philo[++i])
	{
		philo = data->all_philo[i];
		pthread_mutex_lock(data->mutexs.eat);
		if (data->param.n_eat == -1 || data->param.n_eat > philo->nbr_eat)
			return (pthread_mutex_unlock(data->mutexs.eat), 0);
		pthread_mutex_unlock(data->mutexs.eat);
	}
	pthread_mutex_lock(data->mutexs.check);
	data->evryone_is_alive = FALSE;
	pthread_mutex_unlock(data->mutexs.check);
	return (1);
}

static void	toujour_a_table(t_data *data)
{
	int		finish;
	int		i;
	long	duration;

	finish = FALSE;
	while (!finish)
	{
		i = -1;
		while (!finish && data->all_philo[++i])
		{
			duration = get_time_pass(data->t_start);
			if (someone_died(data->all_philo[i], data, duration))
				finish = TRUE;
		}
		if (evryone_to_eat(data))
			finish = TRUE ;
	}
}

void	thread_gestion(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->param.n_philo)
	{
		philo = data->all_philo[i];
		if (pthread_create(&(data->threads[i]), NULL, routine, philo))
			data->err = 7;
	}
	toujour_a_table(data);
	i = -1;
	while (++i < data->param.n_philo)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
			data->err = 8;
	}
}
