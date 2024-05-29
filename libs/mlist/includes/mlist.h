/*
** EPITECH PROJECT, 2024
** library
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    /*  ---- INCLUDE ----*/

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>

    #include "heap.h"

    /*  ---- STRUCTURE ----*/

typedef struct mlist {
    struct mlist *prev;
    void *data;
    struct mlist *next;
} _mlist_t;

typedef _mlist_t *mlist_t;

typedef enum {
    MLIST_POS_FIRST = 0,
    MLIST_POS_BEFORE = 1,
    MLIST_POS_AFTER = 2,
    MLIST_POS_LAST = 3,
} mlist_pos_t;

/**
  * @ingroup mlist
  *
  * @brief Build new mlist node containing the provided data
  *
  * @param data Pointer to object to save (char array, struct...)
  *
  * @return Newly built mlist node
  *
  * @anchor m_list_new
  *
  * @tip
  * Remember !
  * You can stack function together !
  * So, saying `m_list_add_at_pos(ref, m_list_new(ptr), MLIST_POS_LAST)`
  * is 100% valid !
  * Until we meet again !
*/
mlist_t m_list_new(void *data);

/**
  * @ingroup mlist
  *
  * @brief Set a new node to a specific position in a bigger list
  *
  * @param ref Address of the ref list
  * @param obj New node to add (see [m_list_new](#m_list_new))
  * @param pos M_LIST_FIRST, M_LIST_BEFORE, M_LIST_AFTER, M_LIST_LAST
  *
  * @note
  * The 3rd argument is using the ref argument as mark :
  * `M_LIST_BEFORE` means just before the reference
*/
void m_list_add_at_pos(mlist_t *ref, mlist_t obj, mlist_pos_t pos);

/**
  * @ingroup mlist
  *
  * @brief Remove the passed argument of the list he was in,
  *
  * @param obj The node to be deleted
  *
  * @return The data that were in the object
  *
  * @warning
  * It does NOT work like the python pop list method.
  * You need to give an element of the list, not an index.
*/
void *m_list_pop(mlist_t obj);

/**
  * @ingroup mlist
  *
  * @brief Clear out a mlist
  *
  * @param ref A reference to the list to be cleared (does not need to be the
  * beggining)
  * @param destructor If not NULL, it will be called on each element.
*/
void m_list_destroy(mlist_t *ref, void (*destructor)(void *));

/**
  * @ingroup mlist
  *
  * @brief Apply a function to all members of a list
  *
  * @param ref A reference to the list (does not need to be the beggining)
  * @param func Function to be called on each elemnt of the list.
*/
void m_list_apply(mlist_t *ref, void (*func)(void *));

/**
  * @ingroup mlist
  *
  * @brief Get the size of the list
  *
  * @param ref The list to be measured.
  *
  * @return Well, kinda self explanatory, isn't it ?
*/
size_t m_list_size(mlist_t *ref);

/**
  * @ingroup mlist
  *
  * @brief Find an element in the list
  *
  * @param ref The list to be searched
  * @param data Data to be found on the list
  *
  * @return The node containing the data, or NULL if not found
*/
mlist_t m_list_find(mlist_t *ref, void *data);

/**
  * @ingroup mlist
  *
  * @brief Find an element in the list, using a comparaison function
  *
  * @param ref The list to be searched
  * @param data Data to be found on the list
  * @param cmp_func Comparaison function (need to take void pointers)
  *
  * @return The node containing the data, or NULL if not found
*/
mlist_t m_list_smart_find(mlist_t *ref, void *data,
    bool (*cmp_func)(void *, void *));

/**
  * @ingroup mlist
  *
  * @brief Get the value at a given position (it's operator[] (; ))
  *
  * @param ref The list to be used
  * @param pos The index to get the value
  *
  * @return The value found at given position, or NULL if there where an error
*/
void *m_list_get(mlist_t *ref, size_t pos);

#endif
