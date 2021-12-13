/*
** EPITECH PROJECT, 2021
** substract
** File description:
** only contain functions related to subtract values
*/

#include <stdlib.h>
#include "bistromatic.h"

int get_retn(char n1, char n2)
{
    if (n2 > n1)
        return (1);
    return (0);
}

char get_vs(char *nb, int i)
{
    return (nb[my_strlen(nb) - i - 1]);
}

char get_all(char *n1, char *n2, int i, int ret)
{
    return (get_value(get_vs(n1, i), (get_vs(n2, i) - 48 + ret) + 48) + 48);
}

char *infin_subs(char *n1, char *n2)
{
    char *final;
    int i;
    char ret = 0;

    final = malloc(sizeof(char) * (get_bigger_c(n1, n2) + 2));
    for (i = 0; i < get_smaller(n1, n2); i++) {
        final[i] = get_all(n1, n2, i, ret);
        ret = get_retn(get_vs(n1, i), (get_vs(n2, i) - 48 + ret) + 48);
    }
    for (; i < get_bigger_c(n1, n2); i++) {
        final[i] = get_value(n1[my_strlen(n1) - i - 1], ret + 48) + 48;
        ret = get_retn(n1[my_strlen(n1) - i - 1], ret + 48);
    }
    final[i] = '\0';
    return (final);
}
