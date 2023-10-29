/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:58:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 19:02:10 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	init_thread(t_data *data)
{
	if (!data)
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
