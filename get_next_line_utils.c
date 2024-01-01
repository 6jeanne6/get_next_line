/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:02:43 by jewu              #+#    #+#             */
/*   Updated: 2024/01/01 20:43:32 by jewu             ###   ########.fr       */
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

char *ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;
	size_t i;
	size_t j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))
	if (!ptr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	int		j;
	char	*result;

	j = 0;
	result = NULL;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (0);
	while (s[j] != '\0')
	{
		result[j] = s[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == (unsigned char)c)
			return ((char *) &s[j]);
		j++;
	}
	if (s[j] == (unsigned char)c)
		return ((char *) &s[j]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (start + i < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}