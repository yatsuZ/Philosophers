/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:36:24 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 15:40:53 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	end(t_data *data, int err)
{
	if (data && err == 1)
		err = data->err;
	if (err == 1)
		printf("ERROR de malloc.\n");
	else if (err == 3)
		printf("ERROR: ECHEC pour recuper la date d'aujhourdhui.\n");
	else if (err == 4)
		printf("ERROR: Demarage des Threads ont echoue.\n");
	else if (err == 5)
		printf("ERROR: Fermeture des Threads ont echoue.\n");
	if (err == 0)
		printf("\nSUCCES AUCUNE ERREUR DETECTE :)\n");
	return (free_data(data), 0);
}
