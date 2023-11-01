/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:25:33 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 22:40:52 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	init_all_fork(t_data *data, int i)
{
	data->all_fork = ft_calloc(data->n_philo, sizeof(pthread_mutex_t));
	if (!data->all_fork)
		data->err = 1;
	while (!data->err && ++i < data->n_philo)
	{
		data->all_fork[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		if (pthread_mutex_init(data->use_printf, NULL))
			data->err = 6;
	}
}

void	free_all_fork(t_data *data, int i)
{
	if (data->all_fork)
	{
		while (data->all_fork[++i])
		{
			pthread_mutex_destroy(data->all_fork[i]);
			free(data->all_fork[i]);
		}
	}
	free(data->all_fork);
	data->all_fork = NULL;
}

void	init_mutex(t_data *data)
{
	if (!data)
		return ;
	data->use_printf = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->use_printf)
		data->err = 1;
	else if (pthread_mutex_init(data->use_printf, NULL))
		data->err = 6;
	data->check = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->check)
		data->err = 1;
	else if (pthread_mutex_init(data->check, NULL))
		data->err = 6;
	data->eat = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->eat)
		data->err = 1;
	else if (pthread_mutex_init(data->eat, NULL))
		data->err = 6;

	init_all_fork(data, -1);
}

void	free_mutex(t_data *data)
{
	if (!data)
		return ;
	if (data->use_printf)
		pthread_mutex_destroy(data->use_printf);
	free(data->use_printf);
	data->use_printf = NULL;
	if (data->check)
		pthread_mutex_destroy(data->check);
	free(data->check);
	data->check = NULL;
	if (data->eat)
		pthread_mutex_destroy(data->eat);
	free(data->eat);
	data->eat = NULL;
	free_all_fork(data, -1);
}
