/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:30:57 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/04 23:36:26 by yzaoui           ###   ########.fr       */
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
	d->one_dead = FALSE;
	d->param = init_parsing(&(d->err), argc, argv);
	d->mutexs = init_all_mutex(&(d->err), d->param.n_philo);
	d->threads = init_thread(d);
	d->all_philo = ft_init_all_philo(d);
	if (!d->err && gettimeofday(&(d->t_start), NULL) == -1)
		d->err = 5;
	return (d->err);
}

void	free_data(t_data *data)
{
	free_all_philo(data);
	free_thread(data);
	if (data)
		free_mutex(data->mutexs);
	free(data);
	data = NULL;
}
