/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strncpy.c
*/

#include <stddef.h>
#include "include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int count_cpy = 0;

    while (count_cpy < n) {
        dest[count_cpy] = src[count_cpy];
        count_cpy++;
    }
    return (dest);
}
