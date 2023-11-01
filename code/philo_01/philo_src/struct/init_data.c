/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:04:37 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 23:26:26 by yatsu            ###   ########.fr       */
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
	d->evryone_eat = 0;
	d->finish = 0;
	init_parsing(d, argc, argv);
	if (!d->err && gettimeofday(&(d->t_start), NULL) == -1)
		d->err = 5;
	init_thread(d);
	init_mutex(d);
	ft_init_all_philo(d);
	return (d->err);
}

void	free_data(t_data *data)
{
	free_all_philo(data);
	free_mutex(data);
	free_thread(data);
	free_parsing(data);
	free(data);
	data = NULL;
}
