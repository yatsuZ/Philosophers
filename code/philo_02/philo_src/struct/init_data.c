/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:04:37 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 17:17:30 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	init_data(t_data **data, int argc, char **argv)
{
	t_data	*d;

	*(data) = ft_calloc(1, sizeof(t_data));
	if (*data == NULL)
		return (1);
	d = *(data);
	d->err = 0;
	d->evryone_is_alive = TRUE;
	d->time_of_death = -1;
	d->param = init_parsing(&(d->err), argc, argv);
	d->mutexs = init_mutex(&(d->err), d->param.n_philo);
	init_thread(d);
	ft_init_all_philo(d);
	if (!d->err && gettimeofday(&(d->t_start), NULL) == -1)
		d->err = 5;
	return (d->err);
}

void	free_data(t_data *data)
{
	free_all_philo(data);
	free_mutex(data->mutexs);
	free_thread(data);
	free(data);
	data = NULL;
}
