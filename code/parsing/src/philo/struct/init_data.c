/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:16:55 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/22 23:55:46 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../header/philo.h"

t_data	*init_data(int argc, char **argv, int *err)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (*err = 1, NULL);
	data->n_philo = parsing(argc, argv, 0, err);
	data->t_die = parsing(argc, argv, 1, err);
	data->t_eat = parsing(argc, argv, 2, err);
	data->t_sleep = parsing(argc, argv, 3, err);
	data->n_eat = parsing(argc, argv, 4, err);
	data->err = *err;
	if (err)
		return (data);
	return (data);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free(data);
	data = NULL;
}
