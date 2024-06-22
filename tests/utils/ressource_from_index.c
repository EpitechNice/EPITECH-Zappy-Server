/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** ressource_from_index
*/

#include <criterion/criterion.h>
#include "zappy_server.h"
#include "utils.h"

Test(utils_tests, test_ressource_from_index)
{
    char out[10];

    ressource_from_index(FOOD, out);
    cr_assert_str_eq(out, "food");
    ressource_from_index(LINEMATE, out);
    cr_assert_str_eq(out, "linemate");
    ressource_from_index(DERAUMERE, out);
    cr_assert_str_eq(out, "deraumere");
    ressource_from_index(SIBUR, out);
    cr_assert_str_eq(out, "sibur");
    ressource_from_index(MENDIANE, out);
    cr_assert_str_eq(out, "mendiane");
    ressource_from_index(PHIRAS, out);
    cr_assert_str_eq(out, "phiras");
    ressource_from_index(THYSTAME, out);
    cr_assert_str_eq(out, "thystame");
}

