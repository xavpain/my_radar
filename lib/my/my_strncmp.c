/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_strncmp.c
*/

#include "include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (n && s1[i] == s2[i] && s1[i] && s2[i]) {
        i++;
        n--;
    }
    if (n == 0)
        return 0;
    return (s1[i] - s2[i]);
}
