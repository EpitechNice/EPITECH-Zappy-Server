/*
** EPITECH PROJECT, 2024
** heap
** File description:
** garbage_collector
*/

#include "heap.h"

static garbage_list_t garbage_collector_reference;

static garbage_list_t fgcl_create_new(void *ptr)
{
    garbage_list_t new = (garbage_list_t)malloc(sizeof(_garbage_list_t));

    new->prev = NULL;
    new->data = ptr;
    new->next = NULL;
    return new;
}

static void fgcl_add(garbage_list_t new)
{
    garbage_list_t current = garbage_collector_reference;

    if (!current)
        return;
    for (; current->next; current = current->next);
    current->next = new;
    new->prev = current;
}

void fcleanup(void)
{
    garbage_list_t current = garbage_collector_reference;

    if (!garbage_collector_reference)
        return;
    for (; current->prev; current = current->prev);
    for (; current->next; current = current->next) {
        if (!current->prev)
            continue;
        free(current->prev->data);
        free(current->prev);
        current->prev = NULL;
    }
    if (current->prev) {
        free(current->prev->data);
        free(current->prev);
    }
    free(current->data);
    free(current);
    garbage_collector_reference = NULL;
}

void *fmalloc(size_t size)
{
    void *obj = malloc(size);

    if (!obj)
        return NULL;
    for (size_t i = 0; i < size; i++)
        *(char *)(obj + i) = 0;
    if (!garbage_collector_reference)
        garbage_collector_reference = fgcl_create_new(obj);
    else
        fgcl_add(fgcl_create_new(obj));
    return obj;
}

garbage_list_t fget_trash(void *ptr)
{
    garbage_list_t current = garbage_collector_reference;

    if (!current)
        return NULL;
    for (; current->prev; current = current->prev);
    for (; current; current = current->next)
        if (current->data == ptr)
            return current;
    return NULL;
}

void ffree(void *ptr)
{
    garbage_list_t obj = fget_trash(ptr);

    if (!obj)
        return;
    free(obj->data);
    if (obj == garbage_collector_reference)
        garbage_collector_reference = obj->prev ?
            obj->prev : obj->next;
    if (obj->prev)
        obj->prev->next = obj->next;
    if (obj->next)
        obj->next->prev = obj->prev;
    free(obj);
    return;
}
