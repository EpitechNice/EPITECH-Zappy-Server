/*
** EPITECH PROJECT, 2024
** server
** File description:
** file
*/

#include "zappy_server.h"

char *get_file_content(char *filepath)
{
    struct stat file;
    int size;
    char *str;
    int fd;
    int readed;

    stat(filepath, &file);
    size = file.st_size + 1;
    str = (char *)malloc(size);
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    fd = open(filepath, O_RDONLY);
    readed = read(fd, str, size);
    if (readed == 0) {
        toggle_log_on_stderr(true);
        LOG(LOG_LEVEL_ERROR, "Error while reading file %s", filepath);
        toggle_log_on_stderr(false);
    }
    close(fd);
    return str;
}

void read_file(char *filepath)
{
    char *buffer = get_file_content(filepath);

    if (!buffer)
        return;
    printf("%s\n", buffer);
    free(buffer);
}
