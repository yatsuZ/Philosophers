/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:20:13 by yatsu             #+#    #+#             */
/*   Updated: 2023/11/01 15:48:52 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./struct.h"

// Recuperer les parametre (pour le parsing)
void	init_parsing(t_data *data, int argc, char **argv);
void	free_parsing(t_data *data);

// Initialisation et desctructeur
int		init_data(t_data **data, int argc, char **argv);
void	free_data(t_data *data);
void	free_all_philo(t_data *data);
void	ft_init_all_philo(t_data *data);
void	init_thread(t_data *data);
void	free_thread(t_data *data);
void	init_mutex(t_data *data);
void	free_mutex(t_data *data);

// Fonction utile
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_message(long time, int id, char *message, t_data *data);

// Pour les thread
int		on_or_off_all_thread(t_data *data, int param);

void	continue_all_thread(t_data *data);
//FAIRE cette fonction
void	*thread_philo(void *arg);

// TIME
long	ft_sleep(t_data *data, t_philo *philo, long t_sleep, long check_point);
long	get_time_pass(struct timeval start, int *error);

// Dernier foonction
int		end(t_data *data);

#endif