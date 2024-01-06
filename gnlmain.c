/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:38:07 by jewu              #+#    #+#             */
/*   Updated: 2024/01/06 16:55:28 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;
	fd = open("../Main/gnlpersona3.txt", O_RDONLY);
	if (!open)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
/* int	open(const char *path, int oflag)
 *  • opens file specified by path
 *  • return value is a file descriptor = positive integer which is
 *  	a reference to an open file description.
 *  	 → this fd will be used in system calls (read(), ...) to REFER to the open file
 *  • 2 groups of flags:
 *	→ acess modes = O_RDONLY, O_WRONLY, O_RDWR
 *	→ file creations flag = O_CLOEXEC, O_CREAT, O_DIRECTORY, O_EXCL, O_NOCTTY,
 *	  O_NOFOLLOW, O_TMPFILE, O_TRUNC
 * */
