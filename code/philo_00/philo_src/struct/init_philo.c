/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:40:40 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 16:41:23 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

t_philo	*ft_init_philo(t_data *data, int id)
{
	t_philo	*philosophe;

	if (!data)
		return (NULL);
	philosophe = ft_calloc(1, sizeof(t_philo));
	if (!philosophe)
		return (data->err = 1, NULL);
	philosophe->t_last_eat = 0;
	philosophe->data = data;
	philosophe->id = id;
	return (philosophe);
}

void	ft_init_all_philo(t_data *data)
{
	int		i;

	if (!data || data->err)
		return ;
	i = -1;
	data->all_philo = ft_calloc(data->n_philo, sizeof(t_philo));
	if (!data->all_philo)
		data->err = 1;
	while (data->all_philo && !data->err && ++i < data->n_philo)
		data->all_philo[i] = ft_init_philo(data, i);
}

void	free_philo(t_philo *philosophe)
{
	free(philosophe);
	philosophe = NULL;
}

void	free_all_philo(t_data *data)
{
	int	i;

	if (!data || !data->all_philo)
		return ;
	i = -1;
	while (++i < data->n_philo)
		free_philo(data->all_philo[i]);
	free(data->all_philo);
	data->all_philo = NULL;
}
