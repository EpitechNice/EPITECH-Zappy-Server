/*
** EPITECH PROJECT, 2024
** libs
** File description:
** m_list_destroy
*/

#include "mlist.h"

void m_list_destroy(mlist_t *ref, void (*destructor)(void *))
{
    mlist_t tmp;

    if (!ref || !(*ref))
        return;
    for (; (*ref)->prev; *ref = (*ref)->prev);
    for (; *ref; *ref = tmp) {
        tmp = (*ref)->next;
        if (destructor)
            destructor((*ref)->data);
        ffree(*ref);
    }
}
