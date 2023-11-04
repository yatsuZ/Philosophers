/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:36:23 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 15:04:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (init_data(&data, argc, argv))
		return (end(data));
	thread_start(data);
	end(data);
}
