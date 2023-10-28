/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:24:46 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 16:21:08 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	*thread_philo(void *arg)
{
	// t_philo	*philo;
	// philo = (t_philo *)arg;
	(void) arg;
	// char	res;

	// res = (philo->data->n_philo)+48;
	// write(1, &res, 1);
	// write(1, "OK\n Je suis ", 4);
	// write(1, philo->nom, 5);

	printf("OK\n");

	
	// philo->data->nbr_thread_actif++;
	// while (philo->data->nbr_thread_actif != philo->data->n_philo)
	// 	sleep(1);
	// printf("first");
	// printf("\n%d\tBonjour je suis %s\n", philo->id, philo->nom);
	return (NULL);
}
