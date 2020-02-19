/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_show_word_array
*/

#include "include/my.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i]) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
