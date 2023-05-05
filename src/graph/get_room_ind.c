/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** get_room_ind.c
*/

#include "graph.h"

int get_start_room(graph_t *graph)
{
    for (int i = 0; i < graph->size; i++) {
        if (graph->states[i].room_state == START)
            return i;
    }
    return -1;
}

int get_end_room(graph_t *graph)
{
    for (int i = 0; i < graph->size; i++) {
        if (graph->states[i].room_state == END)
            return i;
    }
    return -1;
}
