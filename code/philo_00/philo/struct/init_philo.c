/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:40:40 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 18:54:16 by yatsu            ###   ########.fr       */
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
	philosophe->data = data;
	philosophe->id = id;
	return (philosophe);
}

t_philo	**ft_init_all_philo(t_data *data)
{
	t_philo	**tab;
	int		i;

	if (!data || data->err)
		return (NULL);
	i = -1;
	tab = ft_calloc(data->n_philo, sizeof(t_philo));
	if (!tab)
		return (data->err = 1, NULL);
	while (!data->err && ++i < data->n_philo)
		tab[i] = ft_init_philo(data, i);
	return (tab);
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
