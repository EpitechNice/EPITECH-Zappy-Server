/*
** EPITECH PROJECT, 2024
** libs
** File description:
** new
*/

#include "mlist.h"

mlist_t m_list_new(void *data)
{
    mlist_t obj = (mlist_t)fmalloc(sizeof(_mlist_t));

    obj->data = data;
    return obj;
}
