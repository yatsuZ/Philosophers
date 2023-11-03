/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:20:13 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/03 20:31:41 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./struct.h"

// Recuperer les parametre (pour le parsing)
t_parametre	init_parsing(int *err, int argc, char **argv);

// Initialisation et desctructeur
int			init_data(t_data **data, int argc, char **argv);
void		free_data(t_data *data);
void		free_all_philo(t_data *data);
void		ft_init_all_philo(t_data *data);
void		init_thread(t_data *data);
void		free_thread(t_data *data);
t_all_mutex	init_mutex(int *err, int nombre_de_philo);
void		free_mutex(t_all_mutex mutexs);

// Fonction utile
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_message(long time, t_philo *philo, char *message, t_all_mutex mutexs);

// Pour les thread
void		thread_start(t_data *data);
int			is_finish(t_data *d, t_all_mutex m, t_philo *philo);
int			ft_take_fork(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m);
void		give_fork(t_philo *philo, t_parametre p, t_all_mutex m);
void		give_first_fork(t_philo *philo, t_parametre p, t_all_mutex m);
void		get_first_fork(t_philo *philo, t_parametre p, t_all_mutex m);
int			ft_eat(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m);
int			philo_think(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m);
int			philo_sleep(t_philo *philo, t_data *d, t_parametre p, t_all_mutex m);

//FAIRE cette fonction
void		*routine(void *arg);

// TIME
long		ft_sleep(t_data *data, t_all_mutex mutexs, int t_sleep);
long		get_time_pass(struct timeval start, int *error);

// Dernier foonction
int			end(t_data *data);

#endif