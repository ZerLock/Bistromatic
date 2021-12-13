/*
** EPITECH PROJECT, 2021
** Convert to base n
** File description:
** Convert a string in base 10 to base n
*/

#include "bistromatic.h"
#include <unistd.h>
#include <stdio.h>

char *clean_neg_free(char *nega_val)
{
    char *pos_val;
    int i = 1;

    pos_val = malloc(sizeof(char) * (my_strlen(nega_val) + 2));
    while (nega_val[i]) {
        pos_val[i - 1] = nega_val[i];
        i++;
    }
    pos_val[i - 1] = '\0';
    free(nega_val);
    return (pos_val);
}

int is_null_str(char *str)
{
    int count = 0;
    while (str[count] != '\0') {
        if (str[count] != '0') {
            return (0);
        }
        count++;
    }
    return (1);
}

void my_delete_show_list(numbers_t *list)
{
    numbers_t *tmp;
    numbers_t *tmp_2;

    tmp = list;
    while (tmp != NULL) {
        my_putchar(tmp->c);
        tmp_2 = tmp;
        tmp = tmp->next;
        free(tmp_2);
    }
}

int convert_base_n(char *str, char *base, char *op)
{
    char *base_len = get_clean_string(4);
    int neg = 0;
    my_int_to_string(my_strlen(base), base_len, 0);
    my_revstr(base_len);
    numbers_t *list;
    list = NULL;
    if (str[0] == '-') {
        neg = 1;
        str = clean_neg_free(str);
    }
    my_put_in_list(&list, base[my_getnbr(modulo(str, base_len))]);
    str = division(str, base_len);
    while (!is_null_str(str)) {
        my_put_in_list(&list, base[my_getnbr(modulo(str, base_len))]);
        str = division(str, base_len);
    }
    if (neg == 1)
        my_put_in_list(&list, op[3]);
    my_delete_show_list(list);
}
