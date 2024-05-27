/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "linked_list.h"

int dl_length(lnode_t *head)
{
    int count = 0;

    for (; head != NULL; head = head->next)
        count++;
    return count;
}
