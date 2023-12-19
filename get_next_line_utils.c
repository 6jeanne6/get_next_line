/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:54:09 by jewu              #+#    #+#             */
/*   Updated: 2023/12/14 19:04:14 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t n_memb, size_t size)
{
	char *ptr;
	size_t	i;

	i = 0;
	if (n_memb == 0 || size == 0)
		return (malloc(0));
	if (n_memb > 2147483647 / size)
		return (0);
	ptr = malloc(n_memb * size);
	if (!ptr)
		return (NULL);
	while (i < n_membr * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
