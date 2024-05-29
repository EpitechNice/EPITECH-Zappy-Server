/*
** EPITECH PROJECT, 2024
** libs
** File description:
** m_list_size
*/

#include "mlist.h"

size_t m_list_size(mlist_t *ref)
{
    size_t size = 0;
    mlist_t current;

    if (!ref || !(*ref))
        return 0;
    current = *ref;
    for (; current->prev; current = current->prev);
    for (; current; current = current->next)
        size++;
    return size;
}
