/*
** EPITECH PROJECT, 2021
** get sign of char
** File description:
** get sign of char
*/
#include "bistromatic.h"

int get_sign(char *str)
{
    int i = 1;

    if (*str == '-') {
        for (; i < my_strlen(str); i++)
            str[i - 1] = str[i];
        str[i - 1] = '\0';
        return (-1);
    }
    return (1);
}
