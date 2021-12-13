/*
** EPITECH PROJECT, 2021
** Multiplication
** File description:
** return the result of the multiplication
*/

#include "bistromatic.h"
#include <stdio.h>

int get_time_sign(char *left, char *right)
{
    int sign = 0;
    if (left[0] == '-') {
        left[0] = '0';
        sign++;
    }
    if (right[0] == '-') {
        right[0] = '0';
        sign++;
    }
    if (sign == 0 || sign == 2) {
        return (1);
    }
    return (-1);
}

int char_by_char_calcul(char *left, int r_count, char *tmp_result, char *right)
{
    int left_len = my_strlen(left);
    int tmp = 0;
    for (int l_count = left_len - 1; l_count >= 0; l_count--) {
        tmp_result[r_count + l_count + 1] = (((left[l_count] - 48) * \
        (right[r_count] - 48) + tmp) % 10) + 48;
        tmp = ((left[l_count] - 48) * (right[r_count] - 48) + tmp) / 10;
    }
    return (tmp);
}

void add_big_restaint(int tmp, char *tmp_result, int r_count)
{
    int count = 0;
    while (tmp != 0) {
        tmp_result[r_count + count] = tmp % 10 + 48;
        tmp = tmp / 10;
        count++;
    }
}

char *add_neg_free(char *str)
{
    char *str2;
    int i;

    i = 1;
    str2 = malloc(sizeof(char) * (my_strlen(str) + 2));
    str2[0] = '-';
    for (; i < my_strlen(str) + 1; i++)
        str2[i] = str[i - 1];
    str2[i] = '\0';
    free(str);
    return (str2);
}

char *multiplication(char *left, char *right)
{
    int sign = get_time_sign(left, right);
    int left_len = my_strlen(left);
    int right_len = my_strlen(right);
    char *tmp_result = get_clean_string(left_len + right_len);
    char *result = get_clean_string(left_len + right_len);
    int tmp = 0;
    char *ptr_free;
    for (int r_count = right_len - 1; r_count >= 0; r_count--) {
        tmp = char_by_char_calcul(left, r_count, tmp_result, right);
        add_big_restaint(tmp, tmp_result, r_count);
        ptr_free = result;
        result = addition(result, tmp_result);
        free(ptr_free);
        clean_string(tmp_result);
    }
    free(tmp_result);
    if (sign == -1)
        result = add_neg_free(result);
    return (result);
}
