/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:04:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/10/28 15:05:55 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../header/philo.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;

	if (!s)
		return (NULL);
	cast = (unsigned char *)s;
	while (n--)
		cast[n] = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size, int *err)
{
	void	*pt;
	size_t	totalsize;

	if (*err)
		return (NULL);
	if (!nmemb && !size)
		return (*err = 1, NULL);
	else if (!nmemb || !size)
		return (malloc(0));
	totalsize = size * nmemb;
	if (totalsize / size != nmemb)
		return (*err = 1, NULL);
	pt = malloc(totalsize);
	if (!pt)
		return (*err = 1, NULL);
	ft_memset(pt, 0, totalsize);
	return (pt);
}
