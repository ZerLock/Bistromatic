/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** get char and resturn int
*/

#include "bistromatic.h"
#include <stdlib.h>

int get_signe(char *str, int sign)
{
    int i = 0;

    while (str[i] == '-' || str[i] == '0' || str[i] == '+') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    return (sign);
}

char *my_getnbr2(char *str)
{
    char *number;
    int i = 0;
    int sign = 1;
    int b = 0;

    number = malloc(sizeof(char) * (my_strlen(str) + 2));
    sign = get_signe(str, sign);
    if (sign == -1) {
        number[b] = '-';
        b = 1;
    }
    while (str[i] != '\0' && str[i] != 'a') {
        if (str[i] >= 48 && str[i] <= 57) {
            number[b] = str[i];
            b++;
        }
        i++;
    }
    number[b] = '\0';
    return (number);
}
