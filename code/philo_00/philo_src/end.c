/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:23:12 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 21:18:31 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

void	error_parsing(int error)
{
	if (error == 2)
		printf("NOMBRE d'argument non valide il en faut 5 ou 6.");// CHECK
	else if (error == 3)
		printf("Argument mis en parametre NULL.");// CHECK
	else if (error == 4)
		printf("Echec de conversion en INT\n\
Soit: overflow | non digit | OU | valeur 0 INTERDIT pour un parametre.");//CHECK
}

void	error_thread_and_mutex(int error)
{
	if (error == 6)
		printf("Echec pour la generation des mutex.");
	// if (error == ?)
	// 	printf("Le Demarage des Threads ont echoue.");
	// else if (data->err == ?)
	// 	printf("La Fermeture des Threads ont echoue.");
}

int	end(t_data *data)
{
	if (data && !data->err)
		return (printf("\n\nSUCCES.\n"), free_data(data), 0);
	printf("\nERROR :\t");
	if (!data || data->err == 1)// CHECK
		printf("De malloc.");
	else if (data->err >= 2 && data->err <= 4)
		error_parsing(data->err);
	else if (data->err == 5)
		printf("ECHEC pour recuper la date d'aujhourdhui.");
	else if (data->err >= 6 && data->err <= 6)
		error_thread_and_mutex(data->err);
	return (printf("\n"), free_data(data), 0);
}
