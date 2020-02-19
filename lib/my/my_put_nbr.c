/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_put_nbr
*/

#include "include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 10) {
        my_put_nbr(nb / 10);
    }
    nb = nb % 10;
    my_putchar(nb + 48);
}
