/*
** EPITECH PROJECT, 2021
** do op
** File description:
** do op
*/

#include <unistd.h>
#include "bistromatic.h"
#include <stdlib.h>

char *clean_nega(char *nega_val)
{
    char *pos_val;
    int i = 1;

    pos_val = malloc(sizeof(char) * (my_strlen(nega_val) + 2));
    while (nega_val[i]) {
        pos_val[i - 1] = nega_val[i];
        i++;
    }
    pos_val[i - 1] = '\0';
    return (pos_val);
}

int check_is_only_zeroo(char *t_d)
{
    int i = 0;
    int s = 0;

    while (t_d[i]) {
        if (t_d[i] == '0' || t_d[i] == 'a' || t_d[i] == '-')
            s++;
        i++;
    }
    if (s == my_strlen(t_d))
        return (1);
    return (0);
}

char *do_op(char *f_d, char s_d, char *t_d)
{
    if (s_d == '-') {
        if (t_d[0] == '-')
            t_d = clean_nega(t_d);
        else
            t_d = add_neg(t_d);
        return (addition(f_d, t_d));
    }
    if (s_d == '+')
        return (addition(f_d, t_d));
    if (s_d == '/' && check_is_only_zeroo(t_d) == 1) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    if (s_d == '*')
        return (multiplication(f_d, t_d));
    if (s_d == '/') {
        return (division(f_d, t_d));
    }
    if (s_d == '%')
        return (modulo(f_d, t_d));
}
