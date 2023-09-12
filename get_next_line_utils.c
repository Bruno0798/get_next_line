#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *ft_get_char(char *str, char fetch)
{
    int i;

    i = 0;
    if (!str)
        return NULL;
    while (!str[i])
    {
        if (str[i] == fetch)
            return (&str[i]);
        i++;
    }
    return NULL;
}

char *join(char *temp, char *buffer)
{
    int i;
    int j;
    char *str;

    i = -1;
    j = 0;
    if (!temp)
    {
        temp = malloc(sizeof(char) * 1);
        temp[0] = '\0';
    }
    str = malloc(sizeof(char) * ((ft_strlen(temp) + ft_strlen(buffer)) + 1));
    if (!str)
        return NULL;
    while (temp[++i])
        str[i] = temp[i];
    while (buffer[j])
        str[i++] = buffer[j++];
    str[i] = '\0';
    free(temp);
    return str;
}

char *get_line(char *temp)
{
    int i;
    char *line;

    i = 0;
    if (!temp[i])
        return NULL;
    while (temp[i] != '\0' && temp[i] != '\n')
        i++;
    if (temp[i] == '\0')
        line = malloc(sizeof(char) * (i + 1));
    else
        line = malloc(sizeof(char) * (i + 2));
    if (!line)
        return NULL;
    i = 0;
    while (temp[i] != '\0' && temp[i] != '\n')
    {
        line[i] = temp[i];
        i++;
    }
    if (temp[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return line;
}

char *new_temp(char *temp)
{
    int i;
    int j;
    char *new_temp;

    i = 0;
    j = 0;
    while (temp[i] != '\0' && temp[i] != '\n')
        i++;
    if (temp[i] == '\0')
    {
        free(temp);
        return NULL;
    }
    new_temp = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
    if (!new_temp)
        return NULL;
    i = i + 1;
    while (temp[i])
        new_temp[j++] = temp[i++];
    new_temp[j] = '\0';
    free(temp);
    return new_temp;
}
char *read_and_join(int fd, char *temp)
{
    char *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    bytes_read = 1;
    while (ft_get_char(temp, '\n') == NULL && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(temp);
            return NULL;
        }
        buffer[bytes_read] = '\0';
        if (!buffer)
            return NULL;
        temp = join(temp, buffer);
    }
    free(buffer);
    return temp;
}

char *get_next_line(int fd)
{
    static char *temp;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    temp = read_and_join(fd, temp);
    if (!temp)
        return NULL;
    line = get_line(temp);
    temp = new_temp(temp);
    return line;
}

int main(void)
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    return 0;
}