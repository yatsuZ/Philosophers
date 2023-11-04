/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:20:13 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/04 15:52:02 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./struct.h"

// Initialisation
int			init_data(t_data **data, int argc, char **argv);
t_parametre	init_parsing(int *err, int argc, char **argv);
t_all_mutex	init_mutex(int *err, int nombre_de_philo);
pthread_t	*init_thread(t_data *data);
t_philo		**ft_init_all_philo(t_data *data);
// Desctructeur
void		free_data(t_data *data);
void		free_all_philo(t_data *data);
void		free_thread(t_data *data);
void		free_mutex(t_all_mutex mutexs);

// Pour les thread
void		thread_start(t_data *data);
void		*routine(void *arg);
int			ft_take_fork(t_philo *philo, t_data *d, \
t_parametre p, t_all_mutex m);
void		give_fork(t_philo *philo, t_parametre p, t_all_mutex m);
int			ft_eat(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m);
int			philo_sleep(t_philo *philo, t_data *d, \
t_parametre p, t_all_mutex m);
int			philo_think(t_philo *philo, t_data *d, t_all_mutex m);
int			is_finish(t_data *d, t_all_mutex m);

// Fonction utile
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_message(t_data *d, t_philo *philo, \
char *message, t_all_mutex mutexs);
long		ft_sleep(t_data *data, t_all_mutex mutexs, int t_sleep);
long		get_time_pass(struct timeval start, int *error);
int			end(t_data *data);

#endif