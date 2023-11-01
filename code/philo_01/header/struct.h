/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:20:24 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 23:23:25 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./import.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	t_data	*data;
	long	t_last_eat;
	int		id;
	int		nbr_eat;
}	t_philo;

struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	struct timeval	t_start;
	pthread_t		*threads;
	t_philo			**all_philo;
	pthread_mutex_t	**all_fork;
	pthread_mutex_t	*use_printf;
	pthread_mutex_t	*eat;
	pthread_mutex_t	*check;
	int				evryone_eat;
	int				evryone_is_alive;
	int				finish;
	int				err;
};

#endif