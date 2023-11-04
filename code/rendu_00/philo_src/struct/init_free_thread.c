/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:00:29 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/04 23:34:00 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

pthread_t	*init_thread(t_data *data)
{
	pthread_t	*all_thread;

	if (data->err)
		return (NULL);
	all_thread = ft_calloc(data->param.n_philo, sizeof(pthread_t));
	if (!all_thread)
		data->err = 1;
	return (all_thread);
}

void	free_thread(t_data *data)
{
	if (!data)
		return ;
	free(data->threads);
	data->threads = NULL;
}
