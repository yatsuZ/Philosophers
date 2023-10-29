/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:25:33 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 23:39:14 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	init_mutex(t_data *data)
{
	if (!data)
		return ;
	data->use_printf = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->use_printf)
		data->err = 1;
	else if (pthread_mutex_init(data->use_printf, NULL))
		data->err = 6;
}

void	free_mutex(t_data *data)
{
	if (!data)
		return ;
	if (data->use_printf)
		pthread_mutex_destroy(data->use_printf);
	free(data->use_printf);
	data->use_printf = NULL;
}
