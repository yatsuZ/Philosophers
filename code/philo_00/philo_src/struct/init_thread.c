/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:58:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 23:39:00 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	init_thread(t_data *data)
{
	if (!data || data->err)
		return ;
	data->threads = ft_calloc(data->n_philo, sizeof(pthread_t));
	if (!data->threads)
		data->err = 1;
}

void	free_thread(t_data *data)
{
	if (!data)
		return ;
	free(data->threads);
	data->threads = NULL;
}

int		ON_or_OFF_all_thread(t_data *data, int param)
{
	int	i;

	if (!data || data->err)
		return (1);
	i = -1;
	while (++i < data->n_philo)
	{
		if (param == ON && pthread_create(&(data->threads[i]), NULL, thread_philo, data->all_philo[i]))
			return (data->err = 7, 1);
		else if (param == OFF && pthread_join(data->threads[i], NULL) != 0)
			return (data->err = 8, 1);
	}
	return (0);
}

// void	continue_all_thread(t_data *d)
// {
// 	while (1)
// 	{
// 		if (someone_is_dead(d))
// 			return ;
// 		else if (evryone_eat(d))
// 			return ;
// 	}
// }
