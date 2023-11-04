/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_and_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:05:17 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/04 23:05:42 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

// Printf si possible en respectant les mutexs
void	ft_message(t_philo *philo, char *message, t_all_mutex mutexs)
{
	long	time;

	time = get_time_pass(philo->data->t_start);
	pthread_mutex_lock(mutexs.check);
	if (philo->data->evryone_is_alive == TRUE)
	{
		pthread_mutex_unlock(mutexs.check);
		pthread_mutex_lock(mutexs.use_printf);
		if (philo->data->one_dead == FALSE)
			printf("%ld %d %s\n", time, philo->id + 1, message);
		pthread_mutex_unlock(mutexs.use_printf);
		return ;
	}
	pthread_mutex_unlock(mutexs.check);
}

static void	error_parsing(int error)
{
	if (error == 2)
		printf("NOMBRE d'argument non valide il en faut 5 ou 6.");
	else if (error == 3)
		printf("Argument mis en parametre NULL.");
	else if (error == 4)
		printf("Echec de conversion en INT\n\
Soit: overflow | non digit | OU | valeur 0 INTERDIT pour un parametre.");
}

static void	error_thread_and_mutex(int error)
{
	if (error == 6)
		printf("Echec pour la generation des mutex.");
	if (error == 7)
		printf("Le Demarage des Threads ont echoue.");
	else if (error == 8)
		printf("La Fermeture des Threads ont echoue.");
}

// Fonction de fin qui affiche un message d'erreur si il y en a un
int	end(t_data *data)
{
	if (data && !data->err)
		return (free_data(data), 0);
	printf("\nERROR :\t");
	if (!data || data->err == 1)
		printf("De malloc.");
	else if (data->err >= 2 && data->err <= 4)
		error_parsing(data->err);
	else if (data->err == 5)
		printf("ECHEC pour recuper la date d'aujhourdhui.");
	else if (data->err >= 6 && data->err <= 8)
		error_thread_and_mutex(data->err);
	return (printf("\n"), free_data(data), 0);
}
