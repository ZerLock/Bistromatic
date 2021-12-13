/*
** EPITECH PROJECT, 2021
** infin_mod
** File description:
** infinity modulo
*/

#include "bistromatic.h"
#include <stddef.h>
char *add_neg_free(char *str);

int get_sign_mod(char *str)
{
    int i;

    if (*str == '+') {
        for (i = 0; str[i]; i++)
            str[i] = str[i + 1];
        return (0);
    } else if (*str == '-') {
        for (i = 0; str[i]; i++)
            str[i] = str[i + 1];
        return (1);
    }
    return (0);
}

char *modulo(char *a, char *q)
{
    char *b;
    char *c;
    int sign1;
    int sign2;

    sign1 = get_sign_mod(a);
    sign2 = get_sign_mod(q);
    q = clean_str_div(q);
    if (my_strlen(q) == 1 && *q == '0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
    b = division(a, q);
    c = multiplication(b, q);
    c = add_neg_free(c);
    c = addition(a, c);
    c = clean_str_div(c);
    if (sign1 == 1 || sign1 + sign2 == 2)
        c = add_neg(c);
    return (c);
}
