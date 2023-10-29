/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:25:33 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 18:51:48 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	init_mutex(t_data *data)
{
	if (!data)
		return ;
	if (pthread_mutex_init(data->use_printf, NULL))
		data->err = 6;
}

void	free_mutex(t_data *data)
{
	if (!data)
		return ;
	pthread_mutex_destroy(data->use_printf);
	free(data->use_printf);
	data->use_printf = NULL;
}
