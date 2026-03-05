#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
#endif

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE];
    static int i;
	static int r;
    char *line;
    int j;
	
	j = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(100000);
    if (!line)
        return (NULL);
    while (1)
    {	
        if (i >= r)
        {	
            i = 0;
            r = read(fd, buf, BUFFER_SIZE);
            if (r <= 0)
                break ;
        }
        line[j++] = buf[i++];
        if (line[j - 1] == '\n')
            break ;
    }
	if (r < 0 || j == 0)
	{
		free(line);
		return (NULL);
	}
    line[j] = '\0';
    return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL && i < 2)
	{
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}