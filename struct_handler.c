/*
** EPITECH PROJECT, 2021
** struct handler
** File description:
** to handle struct
*/

#include "bistromatic.h"

int my_put_in_list(numbers_t **list, char c)
{
    numbers_t *element;
    element = malloc(sizeof(*element));
    element->c = c;
    element->next = *list;
    *list = element;
    return (0);
}

int size_struct(numbers_t *list)
{
    int len = 0;
    numbers_t *tmp;
    tmp = list;

    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return (len);
}
