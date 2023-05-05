/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Implementation of printing-related functions used by the parser during
** processing.
*/

#include "parsing.h"

#include "tools.h"

#include <stdbool.h>
#include <stddef.h>

void print_ant_count(int ant_count)
{
    my_putstr("#number_of_ants\n");
    my_put_nbr(ant_count);
    my_putstr("\n\n");
}

void print_room(const char *room_desc)
{
    my_putstr(room_desc);
    my_putchar('\n');
}

void print_tunnel(int a, int b)
{
    my_put_nbr(a);
    my_putchar('-');
    my_put_nbr(b);
    my_putchar('\n');
}

void print_marquee(marquee_type_t type)
{
    static bool shown_marquees[__M_ENUM_END] = {false};
    const char *marquee_str = NULL;

    if (shown_marquees[type])
        return;
    shown_marquees[type] = true;
    switch (type) {
        case M_NO_ANTS:     marquee_str = "#number_of_ants"; break;
        case M_NO_ROOMS:    marquee_str = "#rooms"; break;
        case M_ROOM_START:  marquee_str = "##start"; break;
        case M_ROOM_END:    marquee_str = "##end"; break;
        case M_TUNNELS:     marquee_str = "#tunnels"; break;
        case M_MOVES:       marquee_str = "#moves"; break;
        default: return;
    }

    my_putstr(marquee_str);
    my_putchar('\n');
}
