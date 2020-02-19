/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strncat.c
*/

#include <stddef.h>
#include "include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int end_dest = my_strlen(dest);
    int i = 0;

    while (i < nb && src[i] != '\0') {
        dest[end_dest + i] = src[i];
        i++;
    }
    dest[end_dest + i] = '\0';
    return dest;
}