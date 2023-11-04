/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:40:40 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 16:58:26 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	get_second_fork(int id, t_parametre p)
{
	int	index_fork;

	// if (id % 2 == 0)
	// 	index_fork = id + 1;
	// else
	// 	index_fork = id;
	index_fork = id + 1;
	if (index_fork == p.n_philo)
		index_fork = 0;
	return (index_fork);
}

int	get_first_fork(int id, t_parametre p)
{
	int	index_fork;

	// if (id % 2 == 0)
	// 	index_fork = id;
	// else
	// 	index_fork = id + 1;
	index_fork = id;
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
	philosophe->first_fork = get_first_fork(id, data->param);
	philosophe->second_fork = get_second_fork(id, data->param);
	printf("ID du philo = %d | FIRST fork = %d | second fork = %d\n", id, philosophe->first_fork, philosophe->second_fork);
	philosophe->t_last_eat = 0;
	philosophe->data = data;
	philosophe->nbr_eat = 0;
	philosophe->id = id;
	return (philosophe);
}

t_philo	**ft_init_all_philo(t_data *data)
{
	t_philo	**all_philo;
	int		i;

	if (!data || data->err)
		return (NULL);
	i = -1;
	all_philo = ft_calloc(data->param.n_philo, sizeof(t_philo));
	if (!all_philo)
		data->err = 1;
	while (all_philo && !data->err && ++i < data->param.n_philo)
		all_philo[i] = ft_init_philo(data, i);
	return (all_philo);
}

void	free_all_philo(t_data *data)
{
	int	i;

	if (!data || !data->all_philo)
		return ;
	i = -1;
	while (++i < data->param.n_philo)
	{
		free(data->all_philo[i]);
		data->all_philo[i] = NULL;
	}
	free(data->all_philo);
	data->all_philo = NULL;
}
