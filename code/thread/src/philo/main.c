/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:19:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 14:32:22 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	show_data(t_data *data)
{
	printf("Nombre de seconde ecouler depuis 00:00 UTC le 1er janvier 1970\n");
	printf("%ld s & %ld micros\n", data->t_start.tv_sec, data->t_start.tv_usec);
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
	long	passe_milis;

	data = init_data(argc, argv);
	if (!data || data->err)
		return (end(data));
	// show_data(data);
	printf("START\n\n");
	passe_milis = ft_sleep(data, data->t_die, data->t_eat);
	printf("\n%ld seconde on ecoulé\n", passe_milis / 1000);
	// divise par 1000 pour avoir des seconde
	return (end(data));
}
