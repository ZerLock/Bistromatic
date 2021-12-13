/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** eval expr
*/

#include "bistromatic.h"

char *get_val2add(int id, int end, char *str)
{
    int temp = id;
    int temp2 = id;

    while (id <= end) {
        if ((str[id] == '+' || str[id] == '-') &&
        (check_prevop(str, id - 1, temp - 1) == 0 && str[id - 1] != '(')) {
            str = get_val(temp, id - 1, str);
            temp = id + 1;
        } else if (id == end)
            str = get_val(temp, id, str);
        id++;
    }
    str = get_val(temp2, end, str);
    if (str[temp2] == '-') {
        str[temp2 - 1] = '-';
        str[temp2] = '0';
    } else
        str[temp2 - 1] = '0';
    str[end + 1] = 'a';
    return (str);
}

int get_idopar(char *str)
{
    int i = my_strlen(str) - 1;

    while (i >= 0) {
        if (str[i] == '(')
            return (i);
        i--;
    }
    return (i);
}

char *eval_expr2(args_t *args)
{
    if (get_idopar(args->str) >= 0) {
        args->id = get_idopar(args->str) + 1;
        args->end = get_cl_par(args->str, args->end, args->id) - 1;
        args->str = get_val2add(args->id, args->end, args->str);
        args->id = 0;
        args->end = my_strlen(args->str) - 1;
        eval_expr2(args);
    } else {
        args->str = clean_my_final_str(args->str);
        return (args->str);
    }
}

void add_par(char const *str, char *str2)
{
    int i = 1;

    str2[0] = '(';
    while (str[i - 1] != '\0') {
        str2[i] = str[i - 1];
        i++;
    }
    str2[i] = ')';
    str2[i + 1] = '\0';
}

char *eval_expr(char const *str, unsigned int size)
{
    char *str2;
    args_t *args;

    args = malloc(sizeof(args_t));
    args->str = malloc(sizeof(char) * (my_strlen(str) + (get_m(str) * 3) + 3));
    args->str[my_strlen(str) + (get_m(str) * 3) + 2] = '\0';
    add_par(str, args->str);
    args->str = modify_str(args->str);
    args->id = 0;
    args->end = my_strlen(args->str) - 1;
    args->somme = 0;
    args->tmp = 0;
    return (eval_expr2(args));
}
