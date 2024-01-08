#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*read_and_join(int fd, char *buffer, char *stash)
{
	int (bytes_read) = 1;
	char	*temp;
	
	if (!stash)
		stash = ft_strdup("");
	//while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	while (bytes_read > 0)
	{
		bytes_read = (int)read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return(free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		stash = temp;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*buf;
	//char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	stash = read_and_join(fd, buf, stash);
	if (!stash || stash[0] == '\0')
		return (NULL);
	return (stash);
}

int	main(void)
{
	int	fd;
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
