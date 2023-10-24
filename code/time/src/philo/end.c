/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:36:24 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/24 22:51:54 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	end(t_data *data, int error)
{
	if (error == 1)
		printf("ERROR de malloc.\n");
	else if (error == 3)
		printf("ERROR: ECHEC pour recuper la date d'aujhourdhui.\n");
	return (free_data(data), error);
}
