/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:20:13 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/29 19:10:23 by yatsu            ###   ########.fr       */
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
// long	ft_sleep(t_data *data, long t_sleep, long check_point);

// Pour les thread
// void	*thread_philo(void *arg);

// Dernier foonction
int		end(t_data *data);

#endif