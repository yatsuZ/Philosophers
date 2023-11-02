/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:25:33 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/02 02:49:20 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	init_all_fork(t_all_mutex *mutexs, int i, int nombre_de_philo, int *err)
{
	mutexs->all_fork = ft_calloc(nombre_de_philo, sizeof(pthread_mutex_t));
	if (!mutexs->all_fork)
		*err = 1;
	while (!(*err) && ++i < nombre_de_philo)
	{
		mutexs->all_fork[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		if (pthread_mutex_init(mutexs->all_fork[i], NULL))
			*err = 6;
	}
}

void	free_all_fork(t_all_mutex mutexs, int i)
{
	if (mutexs.all_fork)
	{
		while (mutexs.all_fork[++i])
		{
			pthread_mutex_destroy(mutexs.all_fork[i]);
			free(mutexs.all_fork[i]);
		}
	}
	free(mutexs.all_fork);
	mutexs.all_fork = NULL;
}

t_all_mutex	init_mutex(int *err, int nombre_de_philo)
{
	t_all_mutex	mutexs;

	if (*err)
	{
		mutexs.all_fork = NULL;
		mutexs.check = NULL;
		return (mutexs.eat = NULL, mutexs.use_printf = NULL, mutexs);
	}
	mutexs.use_printf = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!mutexs.use_printf)
		*(err) = 1;
	else if (pthread_mutex_init(mutexs.use_printf, NULL))
		*(err) = 6;
	mutexs.check = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!mutexs.check)
		*(err) = 1;
	else if (pthread_mutex_init(mutexs.check, NULL))
		*(err) = 6;
	mutexs.eat = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!mutexs.eat)
		*(err) = 1;
	else if (pthread_mutex_init(mutexs.eat, NULL))
		*(err) = 6;
	init_all_fork(&mutexs, -1, nombre_de_philo, err);
	return (mutexs);
}

void	free_mutex(t_all_mutex mutexs)
{
	if (mutexs.use_printf)
		pthread_mutex_destroy(mutexs.use_printf);
	free(mutexs.use_printf);
	mutexs.use_printf = NULL;
	if (mutexs.check)
		pthread_mutex_destroy(mutexs.check);
	free(mutexs.check);
	mutexs.check = NULL;
	if (mutexs.eat)
		pthread_mutex_destroy(mutexs.eat);
	free(mutexs.eat);
	mutexs.eat = NULL;
	free_all_fork(mutexs, -1);
}
