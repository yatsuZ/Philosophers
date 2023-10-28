/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:16:55 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 15:28:23 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../header/philo.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;
	int		err;

	err = 0;
	data = ft_calloc(1, sizeof(t_data), &err);
	if (!data)
		return (NULL);
	data->err = 0;
	data->n_philo = parsing(argc, argv, 0, &(data->err));
	data->t_die = parsing(argc, argv, 1, &(data->err));
	data->t_eat = parsing(argc, argv, 2, &(data->err));
	data->t_sleep = parsing(argc, argv, 3, &(data->err));
	data->n_eat = parsing(argc, argv, 4, &(data->err));
	if (!(data->err) && gettimeofday(&(data->t_start), NULL) == -1)
		return (data->err = 3, data);
	data->threads = ft_calloc(data->n_philo, sizeof(pthread_t), &(data->err));
	data->all_philo = ft_init_all_philo(data);
	return (data);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_all_philo(data);
	free(data->threads);
	free(data);
	data = NULL;
}
