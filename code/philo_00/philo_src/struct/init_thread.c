/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:58:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 18:42:32 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	init_thread(t_data *data)
{
	if (!data || data->err)
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

int	on_or_off_all_thread(t_data *data, int param)
{
	int	i;

	if (!data || data->err)
		return (1);
	i = -1;
	while (++i < data->n_philo)
	{
		if (param == ON && pthread_create(&(data->threads[i]), NULL, \
		thread_philo, data->all_philo[i]))
			return (data->err = 7, 1);
		else if (param == OFF && pthread_join(data->threads[i], NULL) != 0)
			return (data->err = 8, 1);
	}
	return (0);
}

int	is_dead(t_data *d)
{
	int		i;
	t_philo	*p;
	long	duration;

	i = 0;
	while (d->all_philo[i])
	{
		p = d->all_philo[i++];
		duration = get_time_pass(d->t_start, &(d->err));
		if (d->err)
			return (1);
		if (duration - p->t_last_eat >= d->t_die)
		{
			ft_message(get_time_pass(p->data->t_start, &(p->data->err)), p->id, "died", d);
			pthread_mutex_lock(d->write_data);
			d->evryone_is_alive = FALSE;
			pthread_mutex_unlock(d->write_data);
			return (1);
		}
	}
	return (0);
}

void	continue_all_thread(t_data *d)
{
	int	vrai;

	vrai = TRUE;
	while (vrai)
	{
		if (is_dead(d))// Faire une boucle qui verifie pour chaque philo si ils ont pas deppase leur t_death
			vrai = FALSE ;
		else if (d->n_eat != -1 && !d->n_eat)
			vrai = FALSE ;
		else if (d->err)
			vrai = FALSE ;
	}
}

