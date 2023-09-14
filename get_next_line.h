#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
char *ft_read_and_join(int fd, char *temp);
char *new_temp(char *temp);
char *get_line(char *temp);
char *join(char *temp, char *buffer);
char *ft_get_char(char *str, char fetch);
int ft_strlen(char *str);

#endif