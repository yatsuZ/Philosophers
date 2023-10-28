/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:36:24 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 14:31:21 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	end(t_data *data)
{
	if (!data || data->err)
		printf("ERROR de malloc.\n");
	else if (data->err == 3)
		printf("ERROR: ECHEC pour recuper la date d'aujhourdhui.\n");
	return (free_data(data), 0);
}
