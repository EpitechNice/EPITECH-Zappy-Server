/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** str_append
*/

#include <criterion/criterion.h>
#include "zappy_server.h"
#include "utils.h"

Test(utils_tests, test_str_append)
{
    char *str = strdup("Hello");
    char *str2 = strdup(" World");
    char *str3 = strdup("!");

    str_append(&str, str2);
    cr_assert_str_eq(str, "Hello World");
    str_append(&str, str3);
    cr_assert_str_eq(str, "Hello World!");
    free(str);
    free(str2);
    free(str3);
}
