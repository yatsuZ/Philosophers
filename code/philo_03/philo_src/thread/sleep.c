/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:43:59 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 22:55:15 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	philo_sleep(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	ft_message(get_time_pass(d->t_start, &(d->err)), philo, "sleep", m);
	ft_sleep(d, m, p.t_eat);
	return (0);
}

int	philo_think(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m)
{
	(void)	p;
	
	ft_message(get_time_pass(d->t_start, &(d->err)), philo, "think", m);
	return (0);
}
