/*
** EPITECH PROJECT, 2024
** libs
** File description:
** m_list_find
*/

#include "mlist.h"

mlist_t m_list_find(mlist_t *ref, void *data)
{
    mlist_t current;

    if (!ref || !(*ref))
        return NULL;
    current = *ref;
    for (; current->prev; current = current->prev);
    for (; current; current = current->next)
        if (current->data == data)
            return current;
    return NULL;
}

mlist_t m_list_smart_find(mlist_t *ref, void *data,
    bool (*cmp_func)(void *, void *))
{
    mlist_t current;

    if (!ref || !(*ref))
        return NULL;
    current = *ref;
    for (; current->prev; current = current->prev);
    for (; current; current = current->next)
        if (cmp_func(data, current->data))
            return current;
    return NULL;
}
