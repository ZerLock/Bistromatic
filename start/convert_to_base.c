/*
** EPITECH PROJECT, 2021
** convert to base
** File description:
** like a tiny lib
*/

#include "bistromatic.h"

int give_index_in_str(char c, char *base)
{
    int count = 0;
    while (base[count] != c && base[count] != 0) {
        count++;
    }
    return (count);
}

void add_number_in_list(numbers_t **list, char *to_add)
{
    for (int count = 0; count < my_strlen(to_add); count++) {
        my_put_in_list(list, to_add[count]);
    }
}

void add_operators(char c, char *operators, numbers_t **list)
{
    char my_op = "()+-*/%"[give_index_in_str(c, operators)];
    my_put_in_list(list, my_op);
}
