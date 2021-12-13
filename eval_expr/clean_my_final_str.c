/*
** EPITECH PROJECT, 2021
** clean the final str
** File description:
** clean the final str
*/

#include "bistromatic.h"

char *clean_my_final_str(char *str)
{
    char *str2return;
    int i = 0;
    int b = 0;

    str2return = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (str[0] == '-') {
        str2return[0] = '-';
        b = 1;
    }
    while (str[i] <= 48 || str[i] > 57 && str[i + 1] != 'a')
        i++;
    if (str[i] == 'a')
        return ("0");
    while (str[i] != 'a') {
        str2return[b] = str[i];
        i++;
        b++;
    }
    str2return[b] = '\0';
    return (str2return);
}
