/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_and_time.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:06:31 by yzaoui            #+#    #+#             */
/*   Updated: 2023/11/04 23:06:51 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/philo.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;

	if (!s)
		return (NULL);
	cast = (unsigned char *)s;
	while (n--)
		cast[n] = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;
	size_t	totalsize;

	if (!nmemb && !size)
		return (NULL);
	else if (!nmemb || !size)
		return (malloc(0));
	totalsize = size * nmemb;
	if (totalsize / size != nmemb)
		return (NULL);
	pt = malloc(totalsize);
	if (!pt)
		return (NULL);
	ft_memset(pt, 0, totalsize);
	return (pt);
}

// Renvoie le temp ecoule depuis start en microsecond
long	get_time_pass(struct timeval start)
{
	struct timeval	now;
	long			pass;

	gettimeofday(&(now), NULL);
	pass = now.tv_sec * 1000 + now.tv_usec / 1000;
	pass = pass - (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (pass);
}

// attend time microseconde
void	ft_sleep(long time)
{
	usleep(time * 1000);
}
