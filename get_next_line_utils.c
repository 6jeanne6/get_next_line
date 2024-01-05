/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:54:09 by jewu              #+#    #+#             */
/*   Updated: 2024/01/05 17:06:54 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t (i) = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int (j) = 0;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	size_t (i) = 0;
	size_t (j) = 0;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	int (j) = 0;
	char *(result) = NULL;

	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
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


