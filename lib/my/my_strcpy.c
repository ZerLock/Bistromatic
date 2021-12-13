/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy string
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
