/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** eval_expr
*/

#include "bistromatic.h"

int get_id_idk(char *str, int id)
{
    while (!(str[id] >= 48 && str[id] <= 57) && str[id] != '-')
        id++;
    return (id);
}

int get_m(char const *str)
{
    int s = 0;
    int i = 0;

    while (str[i + 1]) {
        if (str[i] == '-' && str[i + 1] == '(')
            s++;
        i++;
    }
    return (s);
}

char *modify_str(char const *str)
{
    char *str_final;
    int i = 0;
    int b = 0;

    str_final = malloc(sizeof(char) * (my_strlen(str) + (get_m(str) * 3) + 2));
    while (str[i]) {
        str_final[b] = str[i];
        if (str[i] == '-' && str[i + 1] == '(') {
            str_final[b + 1] = '1';
            str_final[b + 2] = '*';
            b += 2;
        }
        i++;
        b++;
    }
    str_final[b] = '\0';
    return (str_final);
}
