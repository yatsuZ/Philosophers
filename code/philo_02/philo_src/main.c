/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:36:23 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 16:37:04 by yatsu            ###   ########.fr       */
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

//POurquoi quand je mets un nombre de fois de mange il beug