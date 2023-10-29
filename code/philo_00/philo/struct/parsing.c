/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:19:22 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 18:52:01 by yatsu            ###   ########.fr       */
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
	return (res);
}

int	parsing(int argc, char **argv, int get_arg, int *error)
{
	int	res;

	get_arg++;
	if (*error || (get_arg == 5 && argc == 5))
		return (-1);
	res = ft_atoi(argv[get_arg], error);
	if (get_arg == 1 && !res)
		*error = 4;

}
void	init_parsing(t_data *data, int argc, int argv)
{
	if (argc < 5 || argc > 6)
		data->err = 2;
	data->n_philo = parsing(argc, argv, 0, &(data->err));
	data->t_die = parsing(argc, argv, 1, &(data->err));
	data->t_eat = parsing(argc, argv, 2, &(data->err));
	data->t_sleep = parsing(argc, argv, 3, &(data->err));
	data->n_eat = parsing(argc, argv, 4, &(data->err));
}

void	free_parsing(t_data *data)
{
	data->n_philo = 0;
	data->t_die = 0;
	data->t_eat = 0;
	data->t_sleep = 0;
	data->n_eat = 0;
}
