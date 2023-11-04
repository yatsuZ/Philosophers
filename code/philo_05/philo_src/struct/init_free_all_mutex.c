/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_all_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:34:54 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/04 23:33:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

static int	init_all_fork(t_all_mutex *mutexs, int nombre_de_philo)
{
	int	err;
	int	i;

	err = 0;
	i = -1;
	mutexs->all_fork = ft_calloc(nombre_de_philo, sizeof(pthread_mutex_t));
	if (!mutexs->all_fork)
		err = 1;
	while (!err && ++i < nombre_de_philo)
	{
		mutexs->all_fork[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		if (!mutexs->all_fork[i])
			err = 1;
		else if (pthread_mutex_init(mutexs->all_fork[i], NULL))
			err = 6;
	}
	return (err);
}

static void	free_all_fork(t_all_mutex mutexs)
{
	int	i;

	i = -1;
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

pthread_mutex_t	*init_mutex(int *err)
{
	pthread_mutex_t	*tmp;

	if (*err)
		return (NULL);
	tmp = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!tmp)
		*err = 1;
	else if (pthread_mutex_init(tmp, NULL))
		*err = 6;
	return (tmp);
}

t_all_mutex	init_all_mutex(int *err, int nombre_de_philo)
{
	t_all_mutex	mutexs;

	mutexs.use_printf = init_mutex(err);
	mutexs.check = init_mutex(err);
	mutexs.eat = init_mutex(err);
	if (*err)
		mutexs.all_fork = NULL;
	else
		*(err) = init_all_fork(&mutexs, nombre_de_philo);
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
	free_all_fork(mutexs);
}
