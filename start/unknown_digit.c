/*
** EPITECH PROJECT, 2021
** unknown digit
** File description:
** syntax error unknown digit
*/

#include "bistromatic.h"

int is_good_digit(char a, char const *digits)
{
    int j;
    int result;

    result = 0;
    for (j = 0; digits[j]; j++) {
        if (a == digits[j])
            result++;
    }
    if (result > 0)
        return (1);
    return (0);
}

int is_good_op(char a, char const *ops)
{
    int k;
    int result;

    result = 0;
    for (k = 0; ops[k]; k++) {
        if (a == ops[k])
            result++;
    }
    if (result > 0)
        return (1);
    return (0);
}

int has_unknown_digit(char const *expr, char const *digits, char const *ops)
{
    int i;
    int good_digit = 1;
    int good_op = 1;

    for (i = 0; expr[i]; i++) {
        good_digit = is_good_digit(expr[i], digits);
        good_op = is_good_op(expr[i], ops);
        if (good_digit == 0 && good_op == 0)
            return (1);
    }
    return (0);
}
