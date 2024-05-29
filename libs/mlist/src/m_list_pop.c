/*
** EPITECH PROJECT, 2024
** libs
** File description:
** m_list_pop
*/

#include "mlist.h"

void *m_list_pop(mlist_t obj)
{
    void *data;

    if (!obj)
        return NULL;
    data = obj->data;
    if (obj->prev)
        obj->prev->next = obj->next;
    if (obj->next)
        obj->next->prev = obj->prev;
    ffree(obj);
    return data;
}
