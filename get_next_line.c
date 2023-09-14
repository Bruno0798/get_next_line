
#include "get_next_line.h"

char *ft_read_and_join(int fd, char *temp)
{
    char *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (ft_strchr(temp, '\n') == NULL && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(temp);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        if (!buffer)
            return (NULL);
        temp = ft_strjoin(temp, buffer);
    }
    free(buffer);
    return (temp);
}

char *get_next_line(int fd)
{
    char *line;
    static char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    temp = ft_read_and_join(fd, temp);
    if (!temp)
        return (NULL);
    line = ft_get_line(temp);
    temp = ft_new_temp(temp);
    return (line);
}