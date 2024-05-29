/*
** EPITECH PROJECT, 2024
** libs
** File description:
** m_list_apply
*/

#include "mlist.h"

void m_list_apply(mlist_t *ref, void (*func)(void *))
{
    mlist_t current;

    if (!func || !ref || !(*ref))
        return;
    current = *ref;
    for (; current->prev; current = current->prev);
    for (; current; current = current->next)
        func(current->data);
}
