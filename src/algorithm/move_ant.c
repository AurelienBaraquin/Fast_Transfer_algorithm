/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** move_ant.c
*/

#include "path.h"

int move_ant(graph_t *graph, ant_t *ant, bool *not_first_print)
{
    if (!ant->seen[ant->room])
        ant->seen[ant->room] = ant->nb_moves + 1;
    ant->nb_moves++;
    if (ant->room == graph->end_room) {
        graph->states[ant->room].state = FREE;
        return 1;
    }
    set_ant_path(graph, ant);
    if (ant->path == NULL)
        return -1;
    if (graph->states[ant->path->steps->prev->ind].state == OCCUPIED)
        return 0;
    graph->states[ant->room].state = FREE;
    ant->room = ant->path->steps->prev->ind;
    print_ant_path(graph, ant, not_first_print);
    if (ant->room != graph->end_room)
        graph->states[ant->room].state = OCCUPIED;
    return 0;
}
