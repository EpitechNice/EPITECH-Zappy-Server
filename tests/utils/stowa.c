/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** utils_tests
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(utils_tests, test_str_to_word_array)
{
    char *str = "Hello World";
    char **tab = stowa(str, " ");

    cr_assert_str_eq(tab[0], "Hello");
    cr_assert_str_eq(tab[1], "World");
}

Test(utils_tests, test_str_to_word_array2)
{
    char *str = "Hello World";
    char **tab = stowa(str, "o");

    cr_assert_str_eq(tab[0], "Hell");
    cr_assert_str_eq(tab[1], " W");
    cr_assert_str_eq(tab[2], "rld");
}

Test(utils_tests, test_str_to_word_array3)
{
    char *str = "Hello World";
    char **tab = stowa(str, " ");

    cr_assert_str_eq(tab[0], "Hello");
    cr_assert_str_eq(tab[1], "World");
    cr_assert_eq(tab[2], NULL);
}
