/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** events
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "radar.h"

void check_key(window_t *window)
{
    if (window->event.key.code == sfKeyS)
        window->s_key *= -1;
    if (window->event.key.code == sfKeyL)
        window->l_key *= -1;
}

void check_event(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event))
        {
            if (window->event.type == sfEvtClosed) {
                sfRenderWindow_close(window->window);
                return;
            }
            if (window->event.type == sfEvtKeyReleased) {
                check_key(window);
                return;
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
                sfRenderWindow_close(window->window);
            return;
        }
}
