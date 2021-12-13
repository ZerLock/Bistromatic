/*
** EPITECH PROJECT, 2021
** my
** File description:
** my
*/

int my_strlene(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr2(char *str)
{
    int i;
    int size;
    int pat;
    char swap;

    pat = my_strlene(str) - 1;
    i = 0;
    while (i <= pat) {
        swap = str[i];
        str[i] = str[pat];
        str[pat] = swap;
        i++;
        pat--;
    }
    return (str);
}
