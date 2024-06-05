/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** free_tab
*/

#include "zappy_server.h"

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}
