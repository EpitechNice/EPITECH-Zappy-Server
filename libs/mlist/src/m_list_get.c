/*
** EPITECH PROJECT, 2024
** libs
** File description:
** m_list_get
*/

#include "mlist.h"

void *m_list_get(mlist_t *ref, size_t pos)
{
    mlist_t current;

    if (!ref || !(*ref))
        return NULL;
    current = *ref;
    for (; current->prev; current = current->prev);
    for (size_t i = 0; i < pos && current; current = current->next)
        i++;
    return (current ? current->data : NULL);
}
