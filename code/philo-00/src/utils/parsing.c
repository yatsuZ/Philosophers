/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:47:40 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/22 23:53:56 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	ft_atoi(char *s, int *error)
{
	size_t	i;
	long	res;

	if (!s || !s[0])
		return (*error = 2, 0);
	res = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') || res > INT_MAX)
			return (*error = 3, 0);
		res = res * 10 + s[i++] - '0';
	}
	return (res);
}

/*
	@param argc = Le nombre d'argument.
	@param argv = Tableau d'argument.
	@param get_arg = Quelle argument recupéré.
	@param error = un pointeur int 0 si tout va bien.
	Parsing recupére les information des argument.
*/
int	parsing(int argc, char **argv, int get_arg, int *error)
{
	int	res;

	if (*error)
		return (0);
	res = 0;
	get_arg = get_arg + 1;
	if (argc < 5 || argc > 6)
		return (*error = 2, printf("\nERROR: NOMBRE d'argument non valide\n"), 0);
	if (get_arg == 5 && argc == 5)
		return (-1);
	res = ft_atoi(argv[get_arg], error);
	if (*error == 2)
		printf("\nERROR: Argument %d NULL ou ne contient rien.\n", get_arg);
	else if (*error == 3)
		printf("\nERROR: Argument %d NON valide.\n\
Caractere non valide | OU | OVERFLOW pour un INT.\n\n", get_arg);
	return (res);
}
