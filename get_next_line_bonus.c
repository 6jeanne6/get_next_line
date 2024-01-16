/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:13:10 by jewu              #+#    #+#             */
/*   Updated: 2024/01/16 16:10:30 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*clean_stash(char *stash)
{
	char	*new_stash;

	int (i) = 0;
	int (j) = 0;
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

	int (i) = 0;
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

	int (bytes_read) = 1;
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
			return (NULL);
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
	static char	*stash[1024];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	stash[fd] = read_and_join(fd, buf, stash[fd]);
	free(buf);
	if (!stash[fd])
		return (NULL);
	line = fetch_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main (void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*line;

// 	fd1 = open("../Main/gnlpersona3.txt", O_RDONLY);
// 	fd2 = open("../Main/gnltestnl.txt", O_RDONLY);
// 	fd3 = open("../Main/gnlandromaque.txt", O_RDONLY);
// 	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
// 	{
// 		printf("ERROR: one of the file cannot be opened!");
// 		return (-1);
// 	}
// 	int	i = 0;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd1);
// 		if (!line)
// 		{
// 			printf("ERROR: the file is empty, please insert text!");
// 			break ;
// 		}
// 		printf("LINE [%d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		if (!line)
// 		{
// 			printf("ERROR: the file is empty, please insert text!");
// 			break ;
// 		}
// 		printf("LINE [%d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		if (!line)
// 		{
// 			printf("ERROR: the file is empty, please insert text!");
// 			break ;
// 		}
// 		printf("LINE [%d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);

// 	return (0);
// }