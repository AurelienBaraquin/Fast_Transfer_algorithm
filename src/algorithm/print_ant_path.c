/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Implementation of the ant path printing function.
*/

#include "path.h"
#include "tools.h"

#include <stdbool.h>

void print_ant_path(graph_t *graph, ant_t *ant, bool *not_first_print)
{
    if (*not_first_print)
        my_putchar(' ');
    *not_first_print = true;

    my_putchar('P');
    my_put_nbr(ant->id);
    my_putchar('-');
    my_putstr(graph->names[ant->room]);
}
