/*
** EPITECH PROJECT, 2021
** infin_div
** File description:
** infinity division BAM BAM BAM
*/

#include "bistromatic.h"
#include <stdlib.h>
#include <stdio.h>

void get_second_if(args_div_t *args, int i)
{
    if (my_strcmp(args->act, args->nbr2) < 0) {
        args->str[i] = '0';
        args->rest = args->act;
    } else if (my_strcmp(args->act, args->nbr2) == 0) {
        args->str[i] = '1';
        args->rest[0] = '0';
        args->rest[1] = '\0';
    } else {
        args->str[i] = div_by_sub(args->nbr2, args->act, args->rest);
    }
}

void get_first_ife(args_div_t *args, int i)
{
    if (my_strlen(args->act) == my_strlen(args->nbr2)) {
        get_second_if(args, i);
    } else if (my_strlen(args->act) > my_strlen(args->nbr2)) {
        args->str[i] = div_by_sub(args->nbr2, args->act, args->rest);
    } else {
        args->str[i] = '0';
        args->rest = args->act;
    }
}

char *get_str_for(args_div_t *args)
{
    int i;

    for (i = 0; i < my_strlen(args->nbr1); i++) {
        args->act = get_val_restaint(args->nbr1[i], args->rest);
        get_first_ife(args, i);
    }
    args->str[i] = '\0';
    return (args->str);
}

char *get_f_str(args_div_t *args)
{
    if (my_strlen(args->nbr2) == 1 && args->nbr2[0] == '1') {
        if ((args->sign1 * args->sign2) == -1)
            args->nbr1 = add_neg(args->nbr1);
        return (args->nbr1);
    }
    if (my_strlen(args->nbr1) < my_strlen(args->nbr2))
        return ("0");
    else if (my_strlen(args->nbr1) == my_strlen(args->nbr2)
    && my_strcmp(args->nbr1, args->nbr2) < 0)
        return ("0");
    args->str = get_str_for(args);
    args->str = clean_str_div(args->str);
    if ((args->sign1 * args->sign2) == -1)
        args->str = add_neg(args->str);
    return (args->str);
}

char *division(char *nbr_u, char *nbr_d)
{
    args_div_t *args;

    args = malloc(sizeof(args_div_t));
    args->nbr1 = malloc(sizeof(char) * (my_strlen(nbr_u) + 4));
    args->nbr2 = malloc(sizeof(char) * (my_strlen(nbr_d) + 4));
    args->sign1 = get_sign(nbr_u);
    args->sign2 = get_sign(nbr_d);
    args->nbr1 = clean_str_div(nbr_u);
    args->nbr2 = clean_str_div(nbr_d);
    args->rest = malloc(sizeof(char) * (my_strlen(args->nbr1) + 4));
    args->act = malloc(sizeof(char) * (my_strlen(args->nbr1) + 2));
    args->str = malloc(sizeof(char) * (my_strlen(args->nbr1) + 4));
    args->str[0] = '0';
    args->str[1] = '\0';
    args->rest[0] = '0';
    args->rest[1] = '\0';
    return (get_f_str(args));
}
