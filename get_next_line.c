/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:00:52 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/09/14 11:00:54 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *ft_read_and_join(int fd, char *temp)
{
    char *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (ft_get_char(temp, '\n') == NULL && bytes_read != 0)
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
        temp = join(temp, buffer);
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
    temp = new_temp(temp);
    return (line);
}

// int main(void)
// {
//     int fd;

//     fd = open("text.txt", O_RDONLY);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     return 0;
// }