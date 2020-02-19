/*
** EPITECH PROJECT, 2019
** main file my_screensaver
** File description:
** init
*/

#include "radar.h"

void display_usage(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n  ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script   The path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h             print the usage and quit\n\n");
    my_putstr("USER INTERACTIONS\n  'L' key     enable/disable");
    my_putstr(" hitboxes and areas.\n");
    my_putstr(" previous animation.\n");
    my_putstr("  'S' key     enable/disable sprites.\n");
    my_putstr("  ESCAPE key  exit the simulation.\n");
}

int my_radar(char *file_path)
{
    data_t *data = read_file(file_path);

    if (data == NULL)
        return 84;
    init_game(data);
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        display_usage();
        return 0;
    }
    return (my_radar(av[1]));
}
