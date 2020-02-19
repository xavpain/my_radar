/*
** EPITECH PROJECT, 2019
** emacs
** File description:
** my_swap.c
*/

#include "include/my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
