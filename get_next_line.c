/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:51 by jewu              #+#    #+#             */
/*   Updated: 2024/01/11 17:53:01 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*clean_stash(char *stash)
{
	char	*new_stash;

	int (i) = 0;
	int (j) = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	i++;
	new_stash = malloc((sizeof(char)) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		// return (free(stash), NULL);
		return (NULL);
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
/* Cleans the previous line to only keep
* the nest line after \n
*/

static char	*fetch_line(char *stash)
{
	char	*line;

	int (i) = 0;
	int (j) = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	//line = calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	while (stash[j] && stash[j] != '\n')
	{
		line[j] = stash[j];
		j++;
	}
	line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

/* In the case stash has saved a bit of the next line,
 * we fetch the previous line until the \n. 
 * */

static char	*read_and_join(int fd, char *buffer, char *stash)
{
	char	*temp;

	int (bytes_read) = 1;
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (!temp || temp[0] == '\0')
		{
			return (free(temp), NULL);
		}
		//free(stash);
		stash = temp;
		if (!stash || stash[0] == '\0')
			return (NULL);
		//free(temp);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	//buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stash = read_and_join(fd, buf, stash);
	free(buf);
	if (!stash)
	{
		//free(stash);
		//stash = NULL;
		return (NULL);
	}
	line = fetch_line(stash);
	stash = clean_stash(stash);
	//free(stash);
	return (line);
}

/* Writes BUFFER_SIZE characters of a file text 
 * in the terminal.
 * */

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("../Main/gnlpersona3.txt", O_RDONLY);
	if (!fd)
		return (-1);
	int (i) = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("ERROR: the file is empty, please insert text!");
			break ;
		}
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

/* Testing get_next_line()
 * This test has to write BUFFER_size characters
 * until the end of the file.
 * */
