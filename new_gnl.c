#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char *read_and_join(int fd, char *temp)
{
    char *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    bytes_read = 1;
}

char *get_next_line(int fd)
{
    char *line;
    static char *temp;

    if (fd == -1 || BUFFER_SIZE <= 0)
        return NULL;
    temp = read_and_join(fd, temp);
}

int main(void)
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    return 0;
}