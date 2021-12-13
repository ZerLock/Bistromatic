/*
** EPITECH PROJECT, 2021
** add neg*
** File description:
** add minus
*/

#include <stdlib.h>
#include "bistromatic.h"

char *add_neg(char *str)
{
    char *str2;
    int i;

    i = 1;
    str2 = malloc(sizeof(char) * (my_strlen(str) + 2));
    str2[0] = '-';
    for (; i < my_strlen(str) + 1; i++)
        str2[i] = str[i - 1];
    str2[i] = '\0';
    return (str2);
}
