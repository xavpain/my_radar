/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_compute_square_root.c
*/

#include "include/my.h"
#include <stdio.h>

int my_compute_square_root(int nb)
{
    int i = 1;
    int result = 1;

    if (nb == 0 || nb == 1)
        return (nb);

    while (result <= nb) {
        i++;
        result = i * i;
    }
    return (i - 1);
}
