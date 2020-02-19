/*
** EPITECH PROJECT, 2019
** file containing window fucntions for my_radar
** File description:
** window init
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>
#include "radar.h"

window_t *init_struct(sfVideoMode mode)
{
    window_t *window = malloc(sizeof(window_t));

    WI mode = mode;
    WI width = WID;
    WI height = HEI;
    WI bitsPerPixel = 32;
    WI timer = create_timer();
    WI clock = sfClock_create();
    WI map = sfTexture_createFromFile("img/map.jpg", NULL);
    WI plane_texture = sfTexture_createFromFile("img/plane.png", NULL);
    WI turret_texture = sfTexture_createFromFile("img/turret.png", NULL);
    WI background = sfSprite_create();
    WI plane = sfSprite_create();
    sfSprite_setTexture(WI background, WI map, sfTrue);
    WI window = sfRenderWindow_create(WI mode, "my_radar",
    sfResize | sfClose, NULL);
    WI l_key = -1;
    WI s_key = -1;
    return window;
}

void display_sprites(window_t *window, data_t *data)
{
    if (WI s_key == -1) {
        for (int i = 0; PLA[i]; i++)
            if (PLA[i]->delay == 0 && PLA[i]->is_arrived == 0)
                sfRenderWindow_drawSprite(WI window, PLA[i]->sprite, NULL);
        for (int i = 0; TUR[i]; i++)
            sfRenderWindow_drawSprite(WI window, TUR[i]->sprite, NULL);
    }
    if (WI l_key == -1) {
        for (int i = 0; PLA[i]; i++)
            if (PLA[i]->delay == 0 && PLA[i]->is_arrived == 0)
                sfRenderWindow_drawRectangleShape(WI window,
                PLA[i]->hitbox, NULL);
        for (int i = 0; TUR[i]; i++)
            sfRenderWindow_drawCircleShape(WI window, TUR[i]->hitbox, NULL);
    }
}

void window_loop(window_t *window, data_t *data)
{
    while (sfRenderWindow_isOpen(WI window)) {
        sfRenderWindow_drawSprite(WI window, WI background, NULL);
        print_clock(window);
        manage_time(PLA, WI is_sec);
        if (is_finished(PLA) == -1)
            break;
        display_sprites(window, data);
        move_sprites(data);
        is_under_turret(data);
        check_collisions(data);
        check_event(window);
        sfRenderWindow_display(WI window);
    }
    sfRenderWindow_destroy(WI window);
    free(window);
}

void init_game(data_t *data)
{
    sfVideoMode mode = {WID, HEI, 32};
    window_t *window = init_struct(mode);
    set_sprites(data, window);
    sfRenderWindow_setFramerateLimit(WI window, 30);
    window_loop(window, data);
}