/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:51 by jewu              #+#    #+#             */
/*   Updated: 2024/11/04 17:21:38 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_stash(char *stash)
{
	char	*new_stash;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!new_stash)
		return (free(stash), NULL);
	i++;
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}

/* Cleans the previous line to only keep
* the next line after \n
*/

static char	*fetch_line(char *stash)
{
	char	*line;
	int	i;

	i = 0;
	if (!stash[i] || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] != '\0' && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

/* In the case stash has saved a bit of the next line,
 * we fetch the previous line until the \n. 
 * */

static char	*read_and_join(int fd, char *buffer, char *stash)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (!temp || temp[0] == '\0')
			return (free(temp), NULL);
		stash = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

/* Reads BUFFER_SIZE bytes, puts BUFFER_SIZE characters to buffer,
 * and stash is joined with buffer in the while loop.
 * */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;

	if (fd == -42)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	stash = read_and_join(fd, buf, stash);
	free(buf);
	if (!stash)
		return (NULL);
	line = fetch_line(stash);
	stash = clean_stash(stash);
	return (line);
}

/* Writes BUFFER_SIZE characters of a file text 
* in the terminal.
 * */
