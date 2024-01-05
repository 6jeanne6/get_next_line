/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:51 by jewu              #+#    #+#             */
/*   Updated: 2024/01/05 20:13:15 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*clean_stash(char *stash)
{
	char	*new;

	return (new);
}

static char	*fetch_line(char *stash, char *line)
{
	int (i) = 0;

	line = malloc(sizeof(char) * 1);
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

static char	*read_and_join(int fd, char *buffer, char *stash)
{
	int (bytes_read) = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		stash = ft_strjoin(buffer, stash);
		free(buffer);
	}
	free(buffer);
	return (stash);
}

/*Reads n bytes and buffer is joined with stash
 * */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	stash = read_and_join(fd, buffer, stash);
	line = fetch_line(stash, line);
	return (line);
}

/* Uses read() to add characters to the stash 
 * ssize_t read(int fildes, void *buf, size_t nbyte)
 * read() attempts to read nbyte bytes of data from the object referenced by the descriptor
 * fildes into the buffer pointed to by buf*/

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line;
	fd = open("gnlpersona3.txt", O_RDONLY);
	if (!fd)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
