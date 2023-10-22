/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:19:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/22 19:35:18 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	main(int argc, char **argv)
{
	int	error = 0;

	printf("Il faut savoir que le temp est en MILLISECONDE\n\n");
	printf("Nombre de philo\t= %d\n", parsing(argc, argv, 0, &error));
	printf("Temp de vie\t\t= %d\n", parsing(argc, argv, 1, &error));
	printf("Temp de manger\t= %d\n", parsing(argc, argv, 2, &error));
	printf("Temp de sommeil\t= %d\n", parsing(argc, argv, 3, &error));
	if (parsing(argc, argv, 4, &error) == -1)
		printf("Nombre de repas = INFINI\n");
	else
		printf("Nombre de repas = %d\n", parsing(argc, argv, 4, &error));
	if (error)
		return (1);
	return (0);
}
