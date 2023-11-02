/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:19:22 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/02 00:39:05 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

int	ft_atoi(char *s, int *error)
{
	size_t	i;
	long	res;

	if (!s || !s[0])
		return (*error = 3, 0);
	res = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') || res > INT_MAX)
			return (*error = 4, 0);
		res = res * 10 + s[i++] - '0';
	}
	if (s[i] || res > INT_MAX)
		return (*error = 4, 0);
	return (res);
}

int	parsing(int argc, char **argv, int get_arg, int *error)
{
	int	res;

	get_arg++;
	if (*error || (get_arg == 5 && argc == 5))
		return (-1);
	res = ft_atoi(argv[get_arg], error);
	if (get_arg == 1 && (!res || res > 1000))
		*error = 4;
	return (res);
}

t_parametre	init_parsing(int *err, int argc, char **argv)
{
	t_parametre	param;

	if (argc < 5 || argc > 6)
		*(err) = 2;
	param.n_philo = parsing(argc, argv, 0, err);
	param.t_die = parsing(argc, argv, 1, err);
	param.t_eat = parsing(argc, argv, 2, err);
	param.t_sleep = parsing(argc, argv, 3, err);
	param.n_eat = parsing(argc, argv, 4, err);
	return (param);
}
