/*
** EPITECH PROJECT, 2021
** eval_expr5
** File description:
** coding style
*/

#include "bistromatic.h"

char *get_nbr_in(char *str, int id, int end)
{
    int j = 0;
    char *nbr;

    nbr = malloc(sizeof(char) * (end - id + 3));
    while (str[id] == '-' || str[id] == '+') {
        nbr[j] = str[id];
        j++;
        id++;
    }
    while (str[id] >= '0' && str[id] <= '9' && id <= end) {
        nbr[j] = str[id];
        j++;
        id++;
    }
    nbr[j] = '\0';
    return (nbr);
}

int get_id_int(char *str, int id, int end)
{
    while (str[id] == '-' || str[id] == '+') {
        id++;
    }
    while (str[id] >= '0' && str[id] <= '9' && id <= end) {
        id++;
    }
    return (id);
}

char *get_parpaing(parpaing_t *val_ac)
{
    int temp;
    char *val;
    char op;

    val = malloc(sizeof(char) * (my_strlen(val_ac->str) + 2));
    while (check_op_all(val_ac->str, val_ac->id + 1, val_ac->end) == 1) {
        temp = val_ac->id;
        val_ac->id = get_id_idk(val_ac->str, val_ac->id);
        val_ac->nbr1 = get_nbr_in(val_ac->str, val_ac->id, val_ac->end);
        val_ac->id = get_id_int(val_ac->str, val_ac->id, val_ac->end);
        op = get_op(val_ac->id - 1, val_ac->end, val_ac->str);
        val_ac->id = while_isnt_op_and_nbr(val_ac->str, op, val_ac->id);
        val_ac->nbr2 = get_nbr_in(val_ac->str, val_ac->id, val_ac->end);
        val_ac->id = get_id_int(val_ac->str, val_ac->id, val_ac->end);
        val = do_op(my_getnbr2(val_ac->nbr1), op, my_getnbr2(val_ac->nbr2));
        val_ac->str = clean_str(val_ac->str, temp, val_ac->id, val);
        val_ac->id = temp;
    }
    return (val_ac->str);
}

char *get_val(int id, int end, char *str)
{
    parpaing_t *val;

    val = malloc(sizeof(parpaing_t));
    val->nbr1 = malloc(sizeof(char) * (end - id + 3));
    val->nbr2 = malloc(sizeof(char) * (end - id + 3));
    val->id = id;
    val->end = end;
    val->str = str;
    val->id = while_is_nbr(val->str, val->nbr1, val->id, val->end);
    return (get_parpaing(val));
}

int check_prevop(char *str, int id, int temp2)
{
    while (id > temp2) {
        if (is_op_d(str[id]) == 1) {
            return (1);
        } else if (str[id] >= 48 && str[id] <= 57) {
            return (0);
        }
        if (is_op(str[id] == 1)) {
            return (0);
        }
        id--;
    }
    return (1);
}
