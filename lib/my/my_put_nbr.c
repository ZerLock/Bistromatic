/*
** EPITECH PROJECT, 2021
** My put nbr
** File description:
** je pense faire au multiple de 10 par de recursif
*/

void my_putchar(char c);

static int my_put_nbr_recur(long nb)
{
    if (nb > 9) {
        my_put_nbr_recur(nb / 10);
    }
    my_putchar(nb % 10 + 48);

    return (0);
}

int my_put_nbr(int nb)
{
    long lg = nb;
    if (lg < 0) {
        my_putchar('-');
        lg = lg * -1;
    }
    my_put_nbr_recur(lg);
    return (0);
}
