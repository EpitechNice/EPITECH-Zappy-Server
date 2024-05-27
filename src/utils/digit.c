/*
** EPITECH PROJECT, 2024
** server
** File description:
** digit
*/

#include "zappy_server.h"

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_digits(char *str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    for (; str[i] != '\0'; i++)
        if (!is_digit(str[i]))
            return false;
    return true;
}
