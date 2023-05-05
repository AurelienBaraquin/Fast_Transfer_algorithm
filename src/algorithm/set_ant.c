/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-alexis.belmonte
** File description:
** create_ant.c
*/

#include "path.h"

ant_t *create_ant(graph_t *graph, int id)
{
    ant_t *res = malloc(sizeof(ant_t));

    res->path = NULL;
    res->id = id;
    res->nb_moves = 0;
    res->room = graph->start_room;
    res->seen = malloc(sizeof(int) * graph->size);
    for (int i = 0; i < graph->size; i++)
        res->seen[i] = 0;
    return res;
}

void delete_ant(ant_t *ant)
{
    free(ant->seen);
    if (ant->path)
        free_path(ant->path);
    free(ant);
}

void set_ant_path(graph_t *graph, ant_t *ant)
{
    int start = ant->room;

    if (ant->path != NULL)
        free_path(ant->path);
    ant->path = get_path(graph, start, graph->end_room, ant->seen);
}
