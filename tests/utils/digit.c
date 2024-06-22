/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** digit
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(utils_tests, test_is_digit)
{
    cr_assert_eq(is_digit('1'), 1);
    cr_assert_eq(is_digit('a'), 0);
    cr_assert_eq(is_digit(' '), 0);
    cr_assert_eq(is_digit('z'), 0);
    cr_assert_eq(is_digit('-'), 0);
    cr_assert_eq(is_digit('0'), 1);
    cr_assert_eq(is_digit('9'), 1);
    cr_assert_eq(is_digit('5'), 1);
}

Test(utils_tests, test_is_digits)
{
    cr_assert_eq(is_digits("123"), 1);
    cr_assert_eq(is_digits("123a"), 0);
    cr_assert_eq(is_digits("123 "), 0);
    cr_assert_eq(is_digits("123z"), 0);
    cr_assert_eq(is_digits("-123"), 1);
    cr_assert_eq(is_digits("-123a"), 0);
    cr_assert_eq(is_digits("-123 "), 0);
    cr_assert_eq(is_digits("-123z"), 0);
}


