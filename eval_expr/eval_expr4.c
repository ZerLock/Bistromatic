/*
** EPITECH PROJECT, 2021
** eval_expr4.c
** File description:
** coding style
*/

#include "bistromatic.h"

char *clean_str(char *str, int id, int end, char *val)
{
    int i = 0;
    int neg_flag = 0;
    clean_t *c_ac;

    c_ac = malloc(sizeof(clean_t));
    c_ac->str = str;
    c_ac->valo = val;
    while (i < my_strlen(str)) {
        c_ac->str[i] = clean_str_t(i, id, end, c_ac);
        i++;
    }
    str = c_ac->str;
    return (str);
}

int check_op_all(char *str, int id, int end)
{
    while (id < end) {
        if (is_op(str[id]) == 1)
            return (1);
        id++;
    }
    return (0);
}

int while_is_nbr(char *str, char *nbr1, int id, int end)
{
    int j = 0;

    if (check_isnbr(str, id, end) == 1) {
        while (id <= end) {
            nbr1[j] = str[id];
            j++;
            id++;
        }
    }
    return (id);
}

int while_isnt_op_and_nbr(char *str, char op, int id)
{
    while (str[id] != op)
        id++;
    id++;
    while (str[id] != '-' && !(str[id] >= '0' && str[id] <= '9'))
        id++;
    return (id);
}
