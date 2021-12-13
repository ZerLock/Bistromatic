/*
** EPITECH PROJECT, 2021
** eval_expr3
** File description:
** coding style
*/

#include "bistromatic.h"

char get_op(int id, int end, char *str)
{
    while (is_op(str[id]) == 0 && id < end)
        id++;
    return (str[id]);
}

int get_size_of_int(int nb)
{
    int i = 0;
    int mult;

    mult = 1;
    if (nb < 0) {
        nb = -nb;
        i++;
    }
    for (; nb - mult >= 0; i++)
        mult *= 10;
    return (i);
}

char clean_str_t(int i, int id, int end, clean_t *c_ac)
{
    if (i >= id && (i - id) < my_strlen(c_ac->valo))
        return (c_ac->valo[i - id]);
    else if (i <= id || i >= end)
        return (c_ac->str[i]);
    else
        return ('a');
}
