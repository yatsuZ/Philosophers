/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:19:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 21:57:20 by yatsu            ###   ########.fr       */
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
/*
int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;
	i = -1;
	data = init_data(argc, argv);
	if (!data || data->err)
		return (end(data, 1));

	data->nbr_thread_actif = 0;
	//Création des threads
	while (++i < data->n_philo)
	{
		if (pthread_create(&(data->threads[i]), \
		NULL, thread_philo, data->all_philo[i]))
			return(end(data, 4));
//return une erreur si pb a la creation
	}
	//attendre la fin des threads
	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
			return(end(data, 5));
	}
	//Fin d'execution des threads
	printf("NBR de thread actif = %d\n", data->nbr_thread_actif);
	return (end(data, data->err));
}
*/

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = -1;
	data = init_data(argc, argv);
	if (!data || data->err)
		return (end(data, 1));
	data->nbr_thread_actif = 0;
	while (++i < data->n_philo)
	{
		if (pthread_create(&(data->threads[i]), \
		NULL, thread_philo, data->all_philo[i]))
			return (end(data, 4));
	}
	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
			return (end(data, 5));
	}
	printf("NBR de thread actif = %d\n", data->nbr_thread_actif);
	return (end(data, data->err));
}
