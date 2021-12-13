/*
** EPITECH PROJECT, 2021
** eval_expr2
** File description:
** coding style
*/

#include "bistromatic.h"

int check_op_par(char c)
{
    if (c == '(')
        return (1);
    return (0);
}

int check_isnbr(char *str, int id, int end)
{
    while (id <= end) {
        if (str[id] < '0' || str[id] > '9')
            return (0);
        id++;
    }
    return (1);
}

int get_cl_par(char *str, int end, int id)
{
    int i;

    i = id;
    while (str[i]) {
        if (str[i] == ')')
            return (i);
        i++;
    }
    return (end);
}

char is_op_d(char yeps)
{
    if (yeps == '/' || yeps == '*' || yeps == '%')
        return (1);
    return (0);
}

char is_op(char yeps)
{
    if (yeps == '-' || yeps == '+' ||
    yeps == '/' || yeps == '*' || yeps == '%')
        return (1);
    return (0);
}
