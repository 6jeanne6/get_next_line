/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:53:51 by jewu              #+#    #+#             */
/*   Updated: 2023/12/14 19:57:14 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_line(int fd, char *text)
{
	char *buffer;

	buffer = ft_calloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer = read(fd, buffer, BUFFER_SIZE);
}
/*Reads the current line of n bytes
 * */
char *get_next_line(int fd)
{
	static char *stock;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	stock = read_lines(fd, line);
	if (!stock)
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

