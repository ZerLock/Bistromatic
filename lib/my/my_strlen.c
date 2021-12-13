/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** return the number of characters of a string
*/

int my_strlen(char const *str)
{
    int j;

    j = 0;
    while (str[j] != '\0')
        j++;
    return (j);
}
