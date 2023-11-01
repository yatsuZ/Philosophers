/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:43:04 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 21:44:12 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

void	ft_message(long time, int id, char *message, t_data *data)
{
	pthread_mutex_lock(data->use_printf);
	// pthread_mutex_lock(data->check);
	// if (data->evryone_is_alive == FALSE)
	// 	printf("STOP Y A DEJA un mort pour la securité : ");
	// pthread_mutex_unlock(data->check);
	printf("%ld %d %s\n", time, id, message);
	pthread_mutex_unlock(data->use_printf);
}
