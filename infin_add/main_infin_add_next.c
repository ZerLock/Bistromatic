/*
** EPITECH PROJECT, 2021
** main file next
** File description:
** only contain related to main file
*/

#include <stddef.h>
#include "bistromatic.h"
#include <stdlib.h>

int my_str_isnbr(char *nbr)
{
    int i;
    int tgw = 0;

    for (i = 0; i < my_strlen(nbr); i++) {
        if (i == 0 && (nbr[i] == '-' || nbr[i] == '+'))
            tgw++;
        if (nbr[i] >= 48 && nbr[i] <= 57)
            tgw++;
    }
    if (tgw == my_strlen(nbr))
        return (1);
    else
        return (0);
}

int get_sign_of_nbr(char *nbr)
{
    if (nbr[0] == '-')
        return (-1);
    return (1);
}

int error_check(char *ag1, char *ag2)
{
    if (my_str_isnbr(ag1) == 1 && my_str_isnbr(ag2) == 1)
        return (1);
    return (0);
}

char *clean_s(char *str)
{
    char *res;
    int inc = 0;
    int i = 0;

    res = malloc(sizeof(char) * (my_strlen(str)) + 1);
    if (str[0] == '-' || str[0] == '+')
        i = 1;
    while (str[i] == '0')
        i++;
    for (i; i < my_strlen(str); i++) {
        res[inc] = str[i];
        inc++;
    }
    res[inc] = '\0';
    return (res);
}
