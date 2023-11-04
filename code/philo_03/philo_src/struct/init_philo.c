/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:40:40 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 23:13:09 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	get_second_fork(int id, t_parametre p)
{
	int	index_fork;

	if (id % 2 == 0)
		index_fork = id + 1;
	else
		index_fork = id;
	if (index_fork == p.n_philo)
		index_fork = 0;
	return (index_fork);
}

int	get_first_fork(int id, t_parametre p)
{
	int	index_fork;

	if (id % 2 == 0)
		index_fork = id;
	else
		index_fork = id + 1;
	if (index_fork == p.n_philo)
		index_fork = 0;
	return (index_fork);
}


t_philo	*ft_init_philo(t_data *data, int id)
{
	t_philo	*philosophe;

	if (!data)
		return (NULL);
	philosophe = ft_calloc(1, sizeof(t_philo));
	if (!philosophe)
		return (data->err = 1, NULL);
	philosophe->first_fork = get_first_fork(philosophe->id, data->param);
	philosophe->second_fork = get_second_fork(philosophe->id, data->param);
	philosophe->t_last_eat = 0;
	philosophe->data = data;
	philosophe->id = id;
	philosophe->nbr_eat = 0;
	return (philosophe);
}

void	ft_init_all_philo(t_data *data)
{
	int		i;

	if (!data || data->err)
		return ;
	i = -1;
	data->all_philo = ft_calloc(data->param.n_philo, sizeof(t_philo));
	if (!data->all_philo)
		data->err = 1;
	while (data->all_philo && !data->err && ++i < data->param.n_philo)
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
	while (++i < data->param.n_philo)
		free_philo(data->all_philo[i]);
	free(data->all_philo);
	data->all_philo = NULL;
}
