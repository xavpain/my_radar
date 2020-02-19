/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** sprite_setup
*/

#include <time.h>
#include <math.h>
#include "radar.h"

sfVector2f get_vector(plane_t *plane)
{
    float x = (plane->xb - plane->xa);
    float y = (plane->yb - plane->ya);
    float vec_x = x * (plane->speed * 0.00006);
    float vec_y = y * (plane->speed * 0.00006);

    return (sfVector2f){vec_x, vec_y};
}

float get_angle(plane_t *plane)
{
    double slope;

    if (plane->yb-plane->ya == 0)
        return plane->xb > plane->xa ? 90 : 270;
    slope = (plane->xb-plane->xa)/(plane->yb-plane->ya);
    if ((plane->xb < plane->xa && plane->yb > plane->ya)
    || (plane->xb > plane->xa && plane->yb > plane->ya))
        return (180 - ((180/acos(-1.0) * atan(slope))));
    return (360 - ((180/acos(-1.0) * atan(slope))));
}

sfSprite *get_turret_sprite(turret_t *turret, sfTexture *turret_texture)
{
    sfSprite *sprite = sfSprite_create();
    sfCircleShape *cir = sfCircleShape_create();
    int rad = turret->radius * (WID * 0.01);
    static int i = -1;

    srand(time(0) + ++i);
    sfCircleShape_setOrigin(cir, (sfVector2f){10, 10});
    sfCircleShape_setOutlineColor(cir, sfYellow);
    sfCircleShape_setFillColor(cir, (sfColor){rand(), rand(), rand(), 60});
    sfCircleShape_setOutlineThickness(cir, 1);
    sfCircleShape_setPosition(cir, (sfVector2f){turret->x - rad + 10,
    turret->y - rad + 10});
    sfCircleShape_setRadius(cir, rad);
    turret->hitbox = cir;
    sfSprite_setOrigin(sprite, (sfVector2f){10, 10});
    sfSprite_setPosition(sprite, (sfVector2f){turret->x, turret->y});
    sfSprite_setTexture(sprite, turret_texture, sfTrue);
    return sprite;
}

sfSprite *get_plane_sprite(plane_t *plane, sfTexture *plane_texture)
{
    sfSprite *sprite = sfSprite_create();
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setSize(rect, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(rect, (sfVector2f){10, 10});
    sfRectangleShape_rotate(rect, get_angle(plane));
    sfRectangleShape_setPosition(rect, (sfVector2f){plane->xa, plane->ya});
    plane->hitbox = rect;
    sfSprite_setPosition(sprite, (sfVector2f){plane->xa, plane->ya});
    sfSprite_setTexture(sprite, plane_texture, sfTrue);
    sfSprite_setOrigin(sprite, (sfVector2f){10, 10});
    sfSprite_rotate(sprite, get_angle(plane));
    return sprite;
}

void set_sprites(data_t *data, window_t *window)
{
    for (int i = 0; PLA[i]; i++)
        PLA[i]->sprite = get_plane_sprite(PLA[i],
        window->plane_texture);
    for (int i = 0; TUR[i]; i++)
        TUR[i]->sprite = get_turret_sprite(TUR[i],
        window->turret_texture);
}
