/*
** EPITECH PROJECT, 2021
** identical
** File description:
** syntex error
*/

#include "bistromatic.h"

int identical_char_d(char const *str, int i)
{
    int j;

    for (j = i; j < my_strlen(str); j++) {
        if (str[i] == str[j] && i != j)
            return (1);
    }
    return (0);
}

int identical_char(char const *str)
{
    int i;
    int j;
    int result;

    result = 0;
    for (i = 0; i < my_strlen(str); i++) {
        result = identical_char_d(str, i);
        if (result == 1)
            return (1);
    }
    return (0);
}
