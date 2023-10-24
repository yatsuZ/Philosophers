/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:19:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/25 00:06:01 by yatsu            ###   ########.fr       */
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
	@brief Recupere le temp ecoullé entre start et maintenant
	en milliseconde.
	A note que 1s = 1 000 milliseconde.
*/
long	get_time_pass(struct timeval start, int *error)
{
	struct timeval	now;
	long			pass;

	if (*error)
		return (0);
	if (gettimeofday(&(now), NULL) == -1)
		return (*error = 3, 0);
	pass = now.tv_sec * 1000 + now.tv_usec / 1000;
	pass = pass - (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (pass);
}

long	ft_sleep(t_data *data, long t_sleep, long check_point)
{
	long	pass_s_fix;
	long	duration;
	long	last_dif;

	pass_s_fix = get_time_pass(data->t_start, &(data->err));
	duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
	if (data->err)
		return (0);
	last_dif = duration;
	while (t_sleep > duration)
	{
		if (duration - last_dif > check_point)
		{
			printf("%ld\t\tmicroseconde\n", duration);
			last_dif = duration;
		}
		usleep(50);
		duration = get_time_pass(data->t_start, &(data->err)) - pass_s_fix;
		if (data->err)
			return (0);
	}
	return (duration);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		error;
	long	passe_milis;

	error = 0;
	data = init_data(argc, argv, &error);
	if (error || !data->n_eat)
		return (end(data, error));
	// show_data(data);
	printf("START\n\n");
	passe_milis = ft_sleep(data, data->t_die, data->t_eat);
	printf("\n%ld milliseconde on ecoulé\n", passe_milis);
	return (end(data, data->err));
}
