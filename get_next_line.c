/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:03:54 by jewu              #+#    #+#             */
/*   Updated: 2024/01/01 21:00:10 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*fetch_lines(int fd, char *buf, char *stash)
{
	int i;
	char *new_text;

	if (!stash)
		stash = ft_strdup("");
	stash = ft_strjoin(buf, stash);
}

/*Adds the buffer content to a stash*/

static void read_line(int fd, char *buf, char *stash)
{
	int bytes_read;
	char *buffer;

	while(!new_line(text))
	{
		buffer = ft_calloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		fetch_lines(text, buffer);
	}
	free(buffer);
}

/* Uses read() to read the current line of n bytes */

char *get_next_line(int fd)
{
	static char *stash;
	char	*buf;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	line = read_lines(fd, buf, stash);
	if (!line)
		return (NULL);
	//1. read from fd and add into stock
	//2. extract from stock to line
	//3. clean up stock
	return (line);
}
/* Uses read() to add characters to the stash 
 * ssize_t read(int fildes, void *buf, size_t nbyte)
 * read() attempts to read nbyte bytes of data from the object referenced by the descriptor
 * fildes into the buffer pointed to by buf*/