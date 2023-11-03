/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:20:24 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 17:17:23 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./import.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	t_data	*data;
	int		id;
	long	t_last_eat;
	int		nbr_eat;
}	t_philo;

typedef struct s_parametre
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
}	t_parametre;

typedef struct s_all_mutex
{
	pthread_mutex_t	**all_fork;
	pthread_mutex_t	*use_printf;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*check;
}	t_all_mutex;

struct s_data
{
	t_parametre		param;
	struct timeval	t_start;
	t_philo			**all_philo;
	pthread_t		*threads;
	t_all_mutex		mutexs;
	int				evryone_is_alive;
	long			time_of_death;
	int				err;
};

#endif