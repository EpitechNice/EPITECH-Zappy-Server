/*
** EPITECH PROJECT, 2024
** Server
** File description:
** history
*/

#include "input_output.h"

static lnode_t *history;
int history_index;

lnode_t *get_history(void)
{
    return history;
}

void add_to_index(int value)
{
    history_index += value;
    if (history_index < 0)
        history_index = -1;
}

const char *get_history_element(void)
{
    lnode_t *current = history;

    if (!current)
        return NULL;
    for (int i = 0; i < history_index && current; ++i)
        current = current->next;
    if (!current)
        return NULL;
    return (const char *)current->data;
}
