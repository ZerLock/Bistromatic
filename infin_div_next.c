/*
** EPITECH PROJECT, 2021
** functions related to division
** File description:
** ony division
*/

#include <stdlib.h>
#include "bistromatic.h"

char *clean_str_div(char *str)
{
    int only_zero = 0;
    int i = 0;

    if (str[0] != '0')
        return (str);
    for (i = 0; str[i]; i++) {
        if (str[i] == '0')
            only_zero++;
    }
    if (only_zero == my_strlen(str)) {
        return ("0");
    } else {
        for (i = 0; str[i] == '0';)
            str++;
        str[my_strlen(str)] = '\0';
    }
    return (str);
}

char *clean_less(char *str)
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

char *get_val_restaint(char c, char *restaint)
{
    char *str2;
    int i;

    i = 0;
    str2 = malloc(sizeof(char) * (my_strlen(restaint) + 4));
    for (; i < my_strlen(restaint); i++) {
        str2[i] = restaint[i];
    }
    str2[i] = c;
    str2[i + 1] = '\0';
    str2 = clean_str_div(str2);
    return (str2);
}

char get_result_div(char *actual, char *nbr2, char result)
{
    while (actual[0] != '-') {
        if (nbr2[0] != '-')
            nbr2 = clean_less(nbr2);
        actual = addition(actual, nbr2);
        result++;
    }
    return (result);
}

char *get_actual(char *actual, char *nbr2)
{
    while (actual[0] != '-') {
        if (nbr2[0] != '-')
            nbr2 = clean_less(nbr2);
        actual = addition(actual, nbr2);
    }
    return (actual);
}
