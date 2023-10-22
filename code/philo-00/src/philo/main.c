/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:19:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/22 23:57:12 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	show_data(t_data *data)
{
	printf("Il faut savoir que le temp est en MILLISECONDE\n\n");
	printf("Nombre de philo\t= %d\n", data->n_philo);
	printf("Temp de vie\t\t= %d\n", data->t_die);
	printf("Temp de manger\t= %d\n", data->t_eat);
	printf("Temp de sommeil\t= %d\n", data->t_sleep);
	if (data->n_eat == -1)
		printf("Nombre de repas = INFINI\n");
	else
		printf("Nombre de repas = %d\n", data->n_eat);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		error;

	error = 0;
	data = init_data(argc, argv, &error);
	if (error || !data->n_eat)
		return (end(data, error));
	show_data(data);
	return (end(data, error));
}
