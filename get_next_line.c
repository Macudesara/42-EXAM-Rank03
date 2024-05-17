#include <unistd.h> // For read
#include <stdlib.h> // For malloc && free

char	*get_next_line(int fd)
{
	int		i;
	int		bytes;
	char	*buffer;
	char	c;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	index = 0;
	bytes = read(fd, &c, 1);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (bytes > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
		bytes = read(fd, &c, 1);
	}
	if ((bytes <= 0) && (i == 0))
		return (free(buffer), NULL);
	buffer[i] = '\0';
	return (buffer);
}
