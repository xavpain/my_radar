/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** top right timer related functions
*/

#include "radar.h"

sfText *create_timer(void)
{
    sfFont *font = sfFont_createFromFile("img/font.otf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, (sfVector2f){1860, 20});
    return text;
}

void manage_time(plane_t **planes, int is_sec)
{
    if (is_sec == 0)
        return;
    for (int i = 0; planes[i]; i++)
        if (planes[i]->delay > 0)
            planes[i]->delay--;
}

void print_clock(window_t *window)
{
    sfTime time;
    int printime = 0;
    static int temp = 0;

    time = sfClock_getElapsedTime(WI clock);
    printime = sfTime_asSeconds(time);
    sfText_setString(WI timer, my_itoa(printime));
    if (printime != temp) {
        WI is_sec = 1;
        sfText_setColor(WI timer, (sfColor){rand(), rand(), rand(), 255});
    }
    else
        WI is_sec = 0;
    temp = printime;
    sfRenderWindow_drawText(WI window, WI timer, NULL);
}