/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:07:07 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/04 23:14:48 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (init_data(&data, argc, argv))
		return (end(data));
	thread_gestion(data);
	end(data);
}
