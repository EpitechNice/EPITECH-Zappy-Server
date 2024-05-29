/*
** EPITECH PROJECT, 2024
** libs
** File description:
** m_list_add_at_pos
*/

#include "mlist.h"

static void set_first(mlist_t *ref, mlist_t obj)
{
    mlist_t current = *ref;

    for (; current->prev; current = current->prev);
    current->prev = obj;
    obj->next = current;
}

static void set_before(mlist_t *ref, mlist_t obj)
{
    mlist_t current = *ref;

    if (current->prev) {
        current->prev->next = obj;
        obj->prev = current->prev;
    }
    current->prev = obj;
    obj->next = current;
}

static void set_after(mlist_t *ref, mlist_t obj)
{
    mlist_t current = *ref;

    if (current->next) {
        current->next->prev = obj;
        obj->next = current->next;
    }
    current->next = obj;
    obj->prev = current;
}

static void set_last(mlist_t *ref, mlist_t obj)
{
    mlist_t current = *ref;

    for (; current->next; current = current->next);
    obj->prev = current;
    current->next = obj;
}

void m_list_add_at_pos(mlist_t *ref, mlist_t obj, mlist_pos_t pos)
{
    void (*functions[])(mlist_t *, mlist_t) = {&set_first, &set_before,
        &set_after, &set_last};

    if ((int)pos < 0 || (int)pos > 3)
        return;
    if (!obj || !ref)
        return;
    if (!(*ref)) {
        *ref = obj;
        return;
    }
    functions[pos](ref, obj);
}
