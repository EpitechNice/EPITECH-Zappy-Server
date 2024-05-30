/*
** EPITECH PROJECT, 2024
** library
** File description:
** garbage
*/

#ifndef INCLUDED_GARBAGE_H
    #define INCLUDED_GARBAGE_H
    #define USE_CUSTOM_MALLOC

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>

// ===== types =====

typedef struct _garbage_list {
    struct _garbage_list *prev;
    void *data;
    struct _garbage_list *next;
} _garbage_list_t;

typedef _garbage_list_t *garbage_list_t;

// ===== garbage_collector.c =====

#if defined(__GNUC__)
    #define FREE __attribute__((cleanup(ffree_deref)))
    #define UNUSED __attribute__((unused))
/**
  * @ingroup heap
  *
  * @brief Function used to clear out all allocated chunck of data
  *
  * @tip
  * If you are not using GNU (like using gcc), this function will **NOT** be
  * called when program exit.
  * But, if you are, you don't need to do anything for this function to be
  * executed just before your program exit (after main).
*/
void __attribute__((destructor)) fcleanup(void);
#else
    #error "Smart memory management require GNU !"
#endif

/**
  * @ingroup heap
  *
  * @brief Like malloc, but save the allocated chunk in memory for garbage
  * cleanup once the program ends
  *
  * @param size Size to allocate
  *
  * @note
  * This function acts more like a calloc(), because it also set each newly
  * allocated bytes to 0.
  *
  * @return Newly allocated data, or NULL if allocation failed
*/
void *fmalloc(size_t size);

/**
  * @ingroup heap
  *
  * @brief Dev. Return the list element containing the ptr argument.
  *
  * @param ptr Pointer to search in the trash can.
  *
  * @note There are no real reason to manually use this function if you are not
  * making "extensions" for the garbage collector.
  *
  * @return "garbage bag" containing the pointer, or NULL if not found.
*/
garbage_list_t fget_trash(void *ptr);

/**
  * @ingroup heap
  *
  * @brief Like free, but only work with chunks allocated with fmalloc.
  *
  * @note
  * This also take care of any error that could occure (double free, invalid
  * free...). The cost is that the more you allocate, the longer ffree will
  * take.
*/
void ffree(void *ptr);

// ===== garbage_utils.c =====

/**
  * @ingroup heap
  *
  * @brief Free pointed pointer. Used for FREE macro
  *
  * This function will attempt to dereference a pointer ("\*(void\*\*)") and
  * free it.
  *
  * @danger
  * In case of invalid pointer (for example, a pointer **NOT** pointing to
  * another pointer), there will be an undefined behaviour.
*/
void ffree_deref(void *data);

#endif
