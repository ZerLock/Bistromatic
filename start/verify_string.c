/*
** EPITECH PROJECT, 2021
** verify string
** File description:
** verify the string in input
*/

#include "bistromatic.h"

int is_char_in_str(char op, char *base)
{
    int count_base = 0;
    for (count_base = 0; count_base < my_strlen(base); count_base++) {
        if (op == base[count_base])
            return (1);
    }
    return (0);
}

int check_operator_in_base(char *op, char *base)
{
    for (int count_op = 0; count_op < my_strlen(op); count_op++) {
        if (is_char_in_str(op[count_op], base))
            return (1);
    }
    return (0);
}
