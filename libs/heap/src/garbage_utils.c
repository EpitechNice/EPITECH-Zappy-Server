/*
** EPITECH PROJECT, 2024
** heap
** File description:
** garbage_utils
*/

#include "heap.h"

void ffree_deref(void *data)
{
    ffree(*(void **)data);
}
