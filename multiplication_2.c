/*
** EPITECH PROJECT, 2021
** Multiplication
** File description:
** function to make time
*/

#include <bistromatic.h>
#include <stdio.h>

void clean_string(char *str)
{
    int count = 0;
    while (str[count] != 0) {
        str[count] = '0';
        count++;
    }
}

char *get_clean_string(int size)
{
    char *result = malloc(sizeof(char) * (size + 2));
    int count = 0;

    while (count < size) {
        result[count] = '0';
        count++;
    }
    result[count] = '\0';
    return (result);
}
