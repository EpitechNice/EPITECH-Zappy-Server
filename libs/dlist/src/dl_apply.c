/*
** EPITECH PROJECT, 2024
** dragusheen linked_list-library
** File description:
** library
*/

#include "dlist.h"

void dl_apply_data(lnode_t *head, void func(void *))
{
    if (head == NULL || func == NULL)
        return;
    for (; head != NULL; head = head->next)
        func(head->data);
}

void dl_apply_data_param(lnode_t *head,
    void func(void *, void *), void *param)
{
    if (head == NULL || func == NULL)
        return;
    for (; head != NULL; head = head->next)
        func(head->data, param);
}

void dl_apply_node(lnode_t *head, void func(lnode_t *))
{
    if (head == NULL || func == NULL)
        return;
    for (; head != NULL; head = head->next)
        func(head);
}

void dl_apply_node_param(lnode_t *head,
    void func(lnode_t *, void *), void *param)
{
    if (head == NULL || func == NULL)
        return;
    for (; head != NULL; head = head->next)
        func(head, param);
}
