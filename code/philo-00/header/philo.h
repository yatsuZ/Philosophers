/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:20:13 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/22 23:56:50 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./struct.h"

int		parsing(int argc, char **argv, int get_arg, int *error);
void	*ft_calloc(size_t nmemb, size_t size);
t_data	*init_data(int argc, char **argv, int *err);
void	free_data(t_data *data);
int		end(t_data *data, int error);

#endif