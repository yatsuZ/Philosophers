/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:36:23 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/30 00:22:13 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

/// @brief Mon main, Initialisation -> gestions des threads -> fini
/// @param argc nombre de parametre.
/// @param argv N_philo T_de_survie T_de_mange T_de_sommeil N_de_repas
/// @return 0.
int	main(int argc, char **argv)
{
	t_data	*data;

	if (init_data(&data, argc, argv))
		return (end(data));
	if (on_or_off_all_thread(data, ON))
		return (end(data));
	continue_all_thread(data);
	on_or_off_all_thread(data, OFF);
	end(data);
}
