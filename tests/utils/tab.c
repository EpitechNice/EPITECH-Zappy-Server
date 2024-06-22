/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** tab
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(utils_tests, tab_len)
{
    char *tab[3] = {"Hello", "World", NULL};

    cr_assert_eq(tab_len(tab), 2);
}

Test(utils_tests, tab_len2)
{
    char *tab[2] = {"Hello", NULL};

    cr_assert_eq(tab_len(tab), 1);
}

Test(utils_tests, tab_len3)
{
    char *tab[1] = {NULL};

    cr_assert_eq(tab_len(tab), 0);
}
