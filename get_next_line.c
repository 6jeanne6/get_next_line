/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:51 by jewu              #+#    #+#             */
/*   Updated: 2024/01/08 17:46:42 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*clean_stash(char *stash)
{
	char	*new;

	int (i) = 0;
	int (j) = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new)
		return (NULL);
	while (stash[i] != '\0')
		new[j++] = stash[i++];
	free(stash);
	new[j] = '\0';
	return (new);
}
/*Cleans the previous line to only keep the next
*line after \n
*/

static char	*fetch_line(char *stash, char *line)
{
	int (i) = 0;
	int (j) = 0;

	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	while (stash[j] != '\0' && stash[j] != '\n')
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

/* In the case stash has saved a bit of the next line,
* we fetch the previous line until the \n
*/

static char	*read_and_join(int fd, char *buffer, char *stash)
{
	int (bytes_read) = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = (int)read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		stash = ft_strjoin(buffer, stash);
	}
	free(buffer);
	return (stash);
}

/* Reads BUFFER_SIZE bytes, puts BUFFER_SIZE characters to buffer,
* and buffer is joined with stash in the while
* ssize_t read(int fildes, void *buf, size_t nbyte)
* read() attempts to read nbyte bytes of data from the object referenced by the descriptor
* */

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_strjoin(line, buffer);
	stash = read_and_join(fd, buffer, stash);
	line = fetch_line(stash, line);
	stash = clean_stash(stash);
	return (line);
}

/* Writes BUFFER_SIZE characters of a file text in the terminal
*/

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	fd = open("../Main/gnlpersona3.txt", O_RDONLY);
	if (!fd)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
/*Testing get_next_line function
* This test has to write BUFFER_SIZE characters, 
* until the end of the file
*/
