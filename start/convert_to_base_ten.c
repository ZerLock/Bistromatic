/*
** EPITECH PROJECT, 2021
** convert to base 10
** File description:
** Convert an operation string in base n to base 10 and clear
*/

#include "bistromatic.h"

char *give_clean_string(numbers_t *list)
{
    numbers_t *tmp;
    numbers_t *tmp_2;
    int len = size_struct(list);
    char *str;
    int count = 0;
    tmp = list;
    str = malloc(sizeof(char) * (len + 1));
    while (tmp != NULL) {
        str[count] = tmp->c;
        tmp_2 = tmp;
        tmp = tmp->next;
        free(tmp_2);
        count++;
    }
    str[len] = '\0';
    return (str);
}

char *transfom_number(char *number, char *base, numbers_t **list)
{
    int nb = 0;
    char *nb_str;
    char *result = "0";
    char *power = "1";
    char *str_len = get_clean_string(3);
    my_int_to_string(my_strlen(base), str_len, 0);
    my_revstr(str_len);
    for (int count = my_strlen(number) - 1; count >= 0; count--) {
        nb = give_index_in_str(number[count], base);
        nb_str = get_clean_string(3);
        my_int_to_string(nb, nb_str, 0);
        my_revstr(nb_str);
        result = addition(result, multiplication(power, nb_str));
        power = multiplication(power, str_len);
    }
    add_number_in_list(list, result);
}

void get_nbr_str(char *expr, int end, char *base, numbers_t **list)
{
    char *result = malloc(sizeof(char) * (end + 1));
    for (int count = 0; count < end; count++) {
        result[count] = expr[count];
    }
    result[end] = '\0';
    transfom_number(result, base, list);
    free(result);
}

int convert_number(char *expr, char *op, char *base, numbers_t **list)
{
    int count = 0;
    int was_symbol = 0;
    for (count = 0; count < my_strlen(expr) + 1; count++) {
        if (is_char_in_str(expr[count], op) || expr[count] == 0) {
            get_nbr_str(expr, count, base, list);
            return (count);
        }
    }
}

char *convert_string(char *expr, char *op, char *base)
{
    numbers_t *list;
    list = NULL;
    int count = 0;
    while (my_strlen(expr) > count) {
        if (is_char_in_str(expr[count], op)) {
            add_operators(expr[count], op, &list);
            count = count + 1;
        } else {
            count = count + convert_number(expr + count, op, base, &list);
        }
    }
    return (my_revstr(give_clean_string(list)));
}
