/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:43:59 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 15:44:03 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	philo_sleep(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	ft_message(d, philo, "is sleeping", m);
	ft_sleep(d, m, p.t_eat);
	return (0);
}

int	philo_think(t_philo *philo, t_data *d, t_all_mutex m)
{
	ft_message(d, philo, "is thinking", m);
	return (0);
}
